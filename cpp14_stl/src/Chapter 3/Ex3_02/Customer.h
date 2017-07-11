// ������ ������� ���� �ð����� �����Ѵ�
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
private:
  size_t service_t {};                           // ������� ���� �ð�

public:
  explicit Customer(size_t st = 10) :service_t {st}{}

  // ������� ��� �ð��� ���ҽ�Ų��
  Customer& time_decrement()
  {
    if(service_t > 0)
      --service_t;
    return *this;
  }
  bool done() const { return service_t == 0; }
};
#endif