/// \authors София Казимиренко
/// \authors Николай Матвеев

struct sVector
{
  double *d; ///< Указатель на первый элемент распределенноого в памяти пространства для хранения элементов вектора.
  int n;     ///< Количество элементов в векторе.
  int size;  ///< Максимальный размер вектора, который соответствует количеству памяти, распределенной под него.
};

/** \brief Функция инициализации вектора.
 *
 * Выполняет инициализацию полей структуры sVector
 * @param pV указатель на первый элемент распределенноого в памяти пространства для хранения
 * элементов вектора;
 * @param N количество элементов вектора;
 * @param SZ максимальный размер вектора, который соответствует количеству памяти,
 * распределенной под него.
 */
struct sVector init_V ( double *v, int N, int SZ);

void out_V ( struct sVector V, char *msg );

/**
 * \brief Ввод вектора.
 *
 * Организует диалог для ввода:
 * - количества элементов вектора;
 * - элементов вектора.
*/
void in_V ( struct sVector *V);

/**
 * \brief Скалярное произведение векторов.
 *
 * @param Va количество элементов вектора;
 * @param Vb количество элементов вектора;
*/
double dotProduct_V_V ( const struct sVector Va, const struct sVector Vb );

int dotProduct_S_V ( double S, const struct sVector Va, struct sVector *V_rez);

int addProduct_V_V ( const struct sVector Va, const struct sVector Vb, struct sVector *V_rez);

double norm_V ( const struct sVector V );


