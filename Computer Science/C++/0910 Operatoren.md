---
tags:
  - cpp
links:
---
# Operatoren
- bereits bekannt: `+ - - *= % == << <= -> [] () ! & * new delete ::`...
<!--SR:!2024-08-21,4,270-->

## Operatorpräzedenz


| Precendence | Operator                                                                                          | Name                                                                                                                                                                                                                                                            | Associativity |
| ----------- | ------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------- |
| 1           | ::                                                                                                | scope resolution                                                                                                                                                                                                                                                | none          |
| 2           | .<br>-><br>\[]<br>()<br>\++<br>\--                                                                | member selection(object)<br>member selection(pointer)<br>subscripting<br>function call<br>postfix decrement<br>postfix increment                                                                                                                                | left to right |
## Operatoroverloading

### Example
```cpp
class Vector2d { 
	private: 
		double x_; 
		double y_;
	public:
		Vector2d(double x, double y): x_(x), y_(y) {}
		double x() const { return x_; }
		double y() const { return y_; }
		// definition of ’+’ as member function
		Vector2d operator+(const Vector2d& other) const {
			return Vector2d(x_ + other.x_, y_ + other.y_); 
		}
		// definition of ’*=’ as member function
		Vector2d& operator*=(double scalar) {
			x_ *= scalar; y_ *= scalar;
			return *this;
		}
};
// definition of "<<" as global function
std::ostream& operator<<(std::ostream& os, const Vector2d& v) {
	return os << "(" << v.x() << "," << v.y() << ")";
}
int main() { Vector2d v1(2.0, 3.0);
	v1 *= 1.5; // v1.operator*=(1.5);
	Vector2d v2 = v1 + Vector2d(-0.5, -0.5); // v1.operator+(Vector2d(-0.5, -0.5,))
	std::cout << v2 << std::endl; // operator<<(std::cout, v2)
}
```
