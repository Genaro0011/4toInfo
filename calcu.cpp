#include <iostream>
#include <algorithm> // Para usar std::max

using namespace std;

// Función pura: Solo calcula, no imprime en pantalla
float calcular_nota(float valor_bien, float valor_mal, int cant_bien, int cant_mal);

int main() {
    const float NOTA_MAX = 10.0;
    const int TOTAL_PREGUNTAS = 22; // Cambiado a int porque las preguntas son enteras

    int cant_bien = 0, cant_mal = 0, cant_sr = 0;
    float valor_pregunta_bien = NOTA_MAX / TOTAL_PREGUNTAS;
    float valor_pregunta_mal = (-1.0 / 4.0) * valor_pregunta_bien;

    cout << "=== CONFIGURACIÓN DEL EXAMEN ===" << endl;
    cout << "Cantidad de preguntas: " << TOTAL_PREGUNTAS << "\nNota máxima: " << NOTA_MAX << endl;
    cout << "Valor por respuesta correcta: " << valor_pregunta_bien << "\nValor por respuesta incorrecta: " << valor_pregunta_mal << "\n" << endl;

    // Bucle de validación de datos
    while (true) {
        cout << "Ingrese la cantidad de preguntas CORRECTAS: ";
        cin >> cant_bien;
        cout << "Ingrese la cantidad de preguntas INCORRECTAS: ";
        cin >> cant_mal;
        cout << "Ingrese la cantidad de preguntas SIN RESPONDER: ";
        cin >> cant_sr;

        // Validamos que no haya negativos y que la suma sea exactamente el total
        if (cant_bien >= 0 && cant_mal >= 0 && cant_sr >= 0 && (cant_bien + cant_mal + cant_sr == TOTAL_PREGUNTAS)) {
            break; // Datos válidos, salimos del bucle
        }
        cout << "\n❌ ERROR: Los valores no pueden ser negativos y la suma debe ser igual a " << TOTAL_PREGUNTAS << ". Intente de nuevo.\n" << endl;
    }

    // Cálculos estadísticos (trasladados al main)
    float puntaje_positivo = valor_pregunta_bien * cant_bien;
    float puntaje_negativo = valor_pregunta_mal * cant_mal;
    float puntaje_perdido = cant_sr * valor_pregunta_bien;
    float nota_final = calcular_nota(valor_pregunta_bien, valor_pregunta_mal, cant_bien, cant_mal);

    cout << "\n=== DESGLOSE DE RESULTADOS ===" << endl;
    cout << "Puntaje por aciertos: " << puntaje_positivo << endl;
    cout << "Descuento por errores: " << puntaje_negativo << endl;
    cout << "Puntaje potencial perdido (sin responder): " << puntaje_perdido << endl;
    cout << "---------------------------------------------" << endl;
    cout << "NOTA FINAL: " << nota_final << " / " << NOTA_MAX << endl;

    return 0;
}

float calcular_nota(float valor_bien, float valor_mal, int cant_bien, int cant_mal) {
    float resultado = (valor_bien * cant_bien) + (valor_mal * cant_mal);
    // max(0.0f, resultado) asegura que si la nota da negativa, se muestre 0
    return max(0.0f, resultado);
}
