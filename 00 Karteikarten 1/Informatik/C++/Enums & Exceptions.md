Darf `switch` mit `std::string` kombiniert werden? -> Nein
<!--SR:!2024-07-19,4,270-->
Definiere einen `enum` Ampelfarben. Wo sind Kommas und wo Semikolons zu setzen? -> `enum class traffic_light { RED, YELLOW, GREEN };`
<!--SR:!2024-07-19,4,270-->
Wirf eine Fehlermeldung des Typs `invalid_argument` -> `throw std::invalid_arguemnt("ERROR MSG");`
Lies den Inhalt einer Fehlermeldung aus. -> `e.what();`
Fange einen Fehler ab und gib dessen Error Message auf `cerr` aus.
??
```cpp
try {
	<possibly failing code>
} catch(std::<expected error> &e) {
	std::cerr << e.what() << std::endl;
} catch (...) { // catch ANY error
	std::cerr << "unknown error" << std::endl;
}
```