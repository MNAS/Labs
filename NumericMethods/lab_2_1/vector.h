#ifndef VECTOR_H
#define VECTOR_H

/**
 * \mainpage
 * \authors    София Казимиренко
 * \authors    Николай Матвеев
 */


/** \brief Умножение скаляра на вектор.
 *
 * Выполняет умножение скалярной величины на вектор.
 * @param[in]  scal    Скалярная величина.
 * @param[in]  vector  Вектор.
 * @param[in]  rasmer  Размер вектора.
 * @param[out]  vector_res Вектор-результат.
 * @param[out]  rasmer_res Размер вектора-результата.
 *
 * Для успешного выполнения необходимо чтобы память под вектор результат была распределена
 * в процедуре вызова.
 * \code
 * int main()
 * {
 *  double Va[10]={1,2,3};
 *  double Vb[10];
 *  int int Vb_sz;
 *  vecscal ( 10., Va, 3, Vb, &Vb_sz );
 * }
 * \endcode
 */
int vecscal ( double scal,
              double *vector, int rasmer,
              double *vector_res, int *rasmer_res );

///Вывод вектора на печать.
void vivod ( double *vector, int rasmer, char *msg );

///Сумма двух векторов.
int vecsum ( double *vector_a, int rasmer_a,
             double *vector_b, int rasmer_b,
             double *vector_res, int *rasmer_res );

///Скалярное произведение векторов.
double scalmnog ( double *vector_a, int rasmer_a,
                  double *vector_b, int rasmer_b );

///Определение модуля вектора.
double modul_vec ( double *vector_a, int rasmer_a );

///Ввод вектора
void input ( double *vector, int *razmer );

#endif
