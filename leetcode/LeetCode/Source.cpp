#include <iostream>
#include <iterator>
#include <string>
using namespace std;



class Sales_item {

public:
    std::string isbn() const { return bookNo; }

    Sales_item& operator+(const Sales_item& si) {
        this->price += si.price;
        this->unit_sold += si.unit_sold;
        return *this;
    }
    Sales_item& operator+=(const Sales_item& si) {
        return *this + si;
    }

    friend std::istream& operator>>(std::istream& in, Sales_item& si);
    friend std::ostream& operator<<(std::ostream& out, Sales_item& si);

protected:
    std::string bookNo;
    double price;
    unsigned unit_sold;
};

bool compareIsbn(const Sales_item& i1, const Sales_item& i2) {
    return i1.isbn() < i2.isbn();
}
bool sameIsbn(const Sales_item& i1, const Sales_item& i2) {
    return i1.isbn() == i2.isbn();
}

std::istream& operator>>(std::istream& in, Sales_item& si) {
    in >> si.bookNo>>si.price >> si.unit_sold;
    return in;
}
std::ostream& operator<<(std::ostream& out, Sales_item& si) {
    out << si.price << si.unit_sold;
    return out;
}

int main()
{

    std::istream_iterator<Sales_item> item_in(std::cin), eof3;
    std::ostream_iterator<Sales_item> item_out(std::cout, "\n");

    Sales_item sum = *item_in++;
    while (item_in != eof3) {
        if (item_in->isbn() == sum.isbn()) {
            sum += *item_in++;
        }
        else {
            //TODO: WHY NOT WORKING???
            //            item_out = sum;
            sum += *item_in++;
        }
    }
    //    item_out = sum;

    return 0;
}