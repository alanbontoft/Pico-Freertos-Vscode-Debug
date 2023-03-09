class MathClass
{
private:
    /* data */
    int _value;
public:
    MathClass(int i);
    ~MathClass();
    int multiply(int a,int b);
    void increment(void);
    void set(int i);

    int value() { return _value; }
};