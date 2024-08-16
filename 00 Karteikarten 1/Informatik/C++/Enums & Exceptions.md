Darf `switch` mit `std::string` kombiniert werden? -> Nein
<!--SR:!2024-09-23,51,310-->

Definiere einen `enum` Ampelfarben. Wo sind Kommas und wo Semikolons zu setzen? -> `enum class traffic_light { RED, YELLOW, GREEN };`
<!--SR:!2024-10-06,63,310-->

Wirf eine Fehlermeldung des Typs `invalid_argument` -> `throw std::invalid_arguemnt("ERROR MSG");`
<!--SR:!2024-09-28,56,314-->

Lies den Inhalt einer Fehlermeldung aus. -> `e.what();`
<!--SR:!2024-10-11,63,327-->

Fange einen Fehler ab und gib dessen Error Message auf `cerr` aus.
?
```cpp
try {
	<possibly failing code>
} catch(std::<expected error> &e) {
	std::cerr << e.what() << std::endl;
} catch (...) { // catch ANY error
	std::cerr << "unknown error" << std::endl;
}
```

<!--SR:!2024-10-19,64,332-->
