#include <iostream>
using namespace std;

int main() {

    int n;

    do {
        cout << "Ingrese un numero entero mayor o igual a dos: ";
        cin >> n;
    } while (n < 2 || n > 15);

    int matriz[n][2];
    int vector_resultante[n];

    for (int i = 0; i < n; i++) {
    
        for (int j = 0; j < 2; j++) {
            cin >> matriz[i][j];
        }

        vector_resultante[i] = matriz[i][0] + matriz[i][1];
        cout << "vector_resultante: " << vector_resultante [i]<< endl;
    }
    
if (n==2){
    
int x = vector_resultante[0];
int y = vector_resultante[1];
    
      

        if (x < 0 && y < 0 ){
            cout << "El vector pertenece al cuadrante 3"<< endl;
        }else if (x > 0 && y > 0){
            cout << "El vector pertenece al cuadrante 1" << endl;

        }else if (x > 0 && y < 0){
            cout << "El vector al cuadrante 4" << endl;
        }else if ( x < 0 && y > 0 ){
          cout << "El vector pertenece al cuadrante 2" << endl;
        }
    }

    return 0;
}