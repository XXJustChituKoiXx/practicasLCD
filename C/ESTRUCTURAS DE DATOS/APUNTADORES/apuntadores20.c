    //calcular estadisticas con estructuras y apuntadores
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #define TAM 5
    struct DataEst {
        int arreglo[TAM];
        int numDatos;
        float prom;
        int *ptr; 
    };

    int meterDatos(struct DataEst *miptr){
        if(miptr->ptr >= &miptr -> arreglo[TAM-1]) return 1;
        scanf("%d",miptr->ptr);
        (miptr -> numDatos)++;
        (miptr->ptr)++;
        return 0;
    }

    int calcularEstadisticas(struct DataEst *miptr){
        if(miptr->numDatos == 0){
            printf("\nNo hay datos capturados");
            return 1;
        }

        int suma = 0;
        float sumaCuadrados = 0;
        float desv;
        int *aux;

        // Promedio
        for(aux = miptr->arreglo;aux < miptr->arreglo + miptr->numDatos;aux++){
            suma += *aux;
        }

        miptr->prom = (float)suma / miptr->numDatos;

        // Desviación estándar
        for(aux = miptr->arreglo;aux < miptr->arreglo + miptr->numDatos;aux++){
            sumaCuadrados += pow(*aux - miptr->prom, 2);
        }

        desv = sqrt(sumaCuadrados / miptr->numDatos);

        printf("\nPromedio = %.2f", miptr->prom);
        printf("\nDesviacion estandar = %.2f", desv);

        return 0;
    }

    int menu(){
        int opc;
        printf("\n MENÚ");
        printf("\n 1.Igresar Dato");
        printf("\n 2.Calcular estadisticas");
        printf("\n 3.Salir");
        scanf("%d",&opc);
        return opc;
    }

    int main(){
        struct DataEst miDataEst,*miptr;
        miptr = &miDataEst;
        miptr -> ptr = miptr ->arreglo;
        miptr -> numDatos = 0;
        for(;;){
            switch (menu()){
            case 1:
                if(meterDatos(miptr)!=0){
                    printf("\n Arreglo lleno");
                }else{
                    printf("\n Dato Agrgado");
                }
                break;
            case 2:
                calcularEstadisticas(miptr);
            break;
            case 3:
                exit(0);
                break;
            default:
                break;
            }
        }
        return 0;
    }