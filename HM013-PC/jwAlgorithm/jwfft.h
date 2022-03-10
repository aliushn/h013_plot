#ifndef JWFFT_H
#define JWFFT_H




#include <QObject>
#include <QDebug>



/*
*
*
*               计算傅里叶变换频谱
*
*
* */
#define      MAX_MATRIX_SIZE                4194304             // 2048 * 2048
#define      PI                             3.141592653
#define      MAX_VECTOR_LENGTH              10000




class jwFFT : public QObject
{
    Q_OBJECT

    typedef struct Complex
    {
        double rl;              //实部 用这个当做y轴画图像就可以
        double im;              //虚部
    }Complex;

    public:
    explicit jwFFT(QObject *parent = nullptr);
    //傅里叶转换 频域
    bool fft(Complex inVec[], int  len, Complex outVec[]);

    //逆转换
    bool ifft(Complex  inVec[], int   len, Complex  outVec[]);

    int get_computation_layers(int  num);

    bool is_power_of_two(int  num);

    void test();

signals:

public slots:
};

#endif // JWFFT_H
