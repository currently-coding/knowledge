---
tags:
  - cpp
links:
---
# Operatoren
- bereits bekannt: `+ - - *= % == << <= -> [] () ! & * new delete ::`...

## Operatorpräzedenz

#todo finish table: see slides 3-8

| Precendence | Operator                                                                                          | Name                                                                                                                                                                                                                                                            | Associativity |
| ----------- | ------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------- |
| 1           | ::                                                                                                | scope resolution                                                                                                                                                                                                                                                | none          |
| 2           | .<br>-><br>\[]<br>()<br>\++<br>\--                                                                | member selection(object)<br>member selection(pointer)<br>subscripting<br>function call<br>postfix decrement<br>postfix increment                                                                                                                                | left to right |
| 3           | sizeof<br>\++<br>\--<br>~<br>!<br>-<br>+<br>&<br>*<br>new<br>new\[]<br>delete<br>delete\[]<br>\() | size of object/type<br>prefix increment<br>prefix decrement<br>bitwise NOT<br>logical NOT<br>unary minus<br>unary plus<br>address of<br>indirection<br>allocate storage<br>allocate storage\(array)<br>deallocate storage<br>deallocate storage(arrray)<br>cast | right to left |
| 4           |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 5           |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 6           |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 7           |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 8           |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 9           |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 10          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 11          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 12          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 12          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 13          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 14          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 15          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 16          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
| 17          |                                                                                                   |                                                                                                                                                                                                                                                                 |               |
 
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

# Code Beispiele/Aufgaben
## 1


# Flashcards
