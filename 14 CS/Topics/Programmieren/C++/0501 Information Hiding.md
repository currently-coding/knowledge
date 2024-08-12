---
tags:
  - cpp
links: 
aliases:
  - Sichtbarkeit
  - Zugriffsrechte
---
# Change this heading
- in C++ als **Kapselung** implementiert
- Aufteilung in [[#Schnittstelle]] und [[#Implementierung]]
# in C++
- `public:` -> Zugang nur innerhalb der Klasse
- `private:` -> Zugang für externen Code
## Schnittstelle
- `public:` exposes elements to external code
## Implementierung
- `private:` hides elements from external code


# Code Beispiele/Aufgaben
```cpp
class vector2d {
	double *v; // private

	public:
		vector2d(double x, double y) { // Constructor
			v = new double[]{x, y};
		}
	
		~vector2d() { // Destructor
			delete[] v;
		}
		
		double x() { 
			return v[0];
		}
	
		double y() {
			return this->v[1];
		}
	
		void print() {
			cout << "(" << x() << "," <<
			this->y() << ")" << endl;
		}

		inline void explicit_inline();
};

void vector2d::explicit_inline() {
	std::cout << "Explicit Inline when initializing outside of class\n";
}

int main() {
	vector2d vec; vec.init(1.0, 2.0);
	vec.print();
	vec.destroy();
}
```
- automatisches `inline` bei direkt implementierten Methoden

# Flashcards
