## Krótki opis:

Praktyczne Kółko Programistyczne (aka PKP).
W ramach koła każdy będzie miał okazje
napisać własny język programowania i interpreter do niego. Będzie można 
nauczyć się jak wygląda kompilacja języka od tekstu do programu.
Jednak przede wszystkim celem koła jest nauczanie dobrych praktyk
programistycznych tak żeby dobrze zarządzać projektami i pisać
kod, który da się swobodnie rozwijać. Interpreter jest po prostu
projektem, przy którym dużo można się nauczyć.

## Długi opis:

Tematyką koła jest stworzenie, od początku do końca, małego projektu wprowadzając po drodze
zagadnienia z tematyki inżynierii oprogramowania. Celem kółka jest nauczanie dobrych
praktyk przy tworzeniu projektów programistycznych tak żeby były czytelne i możliwe do rozwijania. 
Tworzonym projektem będzie interpreter autorskiego języka programowania (każdy z uczestników
będzie mógł wymyślić własny, tak długo jak będzie spełniał założenia gramatyk LL(1) co zostanie
wyjaśnione w trakcie kółka). Osoby, które nie będą chciały wymyślić samodzielnie 
języka będą mogły implementować prosty język funkcyjny wymyślony przez prowadzących.
Projekt będzie pisany w C++. 

Zajęcia będą wyglądały następująco. Na początku będzie poprowadzony wykład.
Wykład będzie trwał zapewne od 0.5 do 1 godz. Jeżeli uczestnicy wyrażą chęć
wykłady będą mogły być krótsze, po prostu będą pokrywały mniejszy zakres materiału
na raz. Po wykładzie nastąpi szybkie przedstawienie części praktycznej zajęć.
Następująca jest część praktyczna zajęć, w której uczestnicy będą mogli powtórzyć
sobie informacje przedstawione w trakcie wykładu przez wprowadzenie ich bezpośrednio
do powstającego projektu. Na miejscu będzie 2 prowadzących, którzy w każdej chwili
mogą pomóc. Czas pojedynczych zajęć przewidywany jest od 3 do 4 godz. 
(przy czym nie powinno być problemu żeby wyjść wcześniej, a może nawet zostać dłużej).
Ponieważ zajęć jest mniej niż tygodni w pojedynczym roku akademickim nie ma problemu
żeby część praktyczną dowolnej części kółka przedłużyć o kolejny tydzień.
Mile widziane też będzie eksperymentowanie ze strony uczestników i praca samodzielna 
w domu celem rozwinięcia projektu ponad wymagania przedstawione w trakcie kółka.
W takim wypadku prowadzący też oferują pomoc ze swojej strony.
Ponieważ projekt tworzony będzie z zajęć na zajęcia ważna będzie regularna
obecność ze strony uczestników.
Oczywiście będą też przerwy w trakcie pojedynczych zajęć. 

Plan kółka jest następujący:

0.  Wprowadzenie do tematyki kółka.
    Powtórzenie wymagań. 
    Przedstawienie używanych narzędzi.  
1.  Struktura projektu (rozdzielenie plików nagłówkowych od plików źródłowych). 
    System kontroli wersji (*git*). 
    Systemy budowania (*CMake i make*). 
    Podział projektu na moduły (podział na biblioteki).
2.  Biblioteki zewnętrzne (*boost*).
    Testy jednostkowe (z użyciem *boost-test*).
    Wprowadzenie do metodyki git-flow (gałęzie w systemie kontroli wersji).
3.  Wprowadzenie do tematyki gramatyki języków programowania.
    Proces przetwarzania programu od wersji tekstowej do pliku wykonywalnego.
    Wprowadzenie notacji *EBNF* do zapisu formalnego języka programowania.
    Wprowadzenie wymagań gramatyki *LL(1)*.
    Priorytet operatorów, a gramatyka.
    Opracowanie własnego języka.
4.  Wprowadzenie do programowania obiektowego.
    Klasy bazowe, Klasy abstrakcyjne a interfejsy w programowaniu obiektowym.
    Definicja interfejsu źródła tekstu używając klasy abstrakcyjnej.
    Implementacja interfejsu źródła czytającego znaki z ciągu znaków.
5.  RAII (*Resource Acquisition Is Initialization*) w C++ na przykładzie smart pointerów.
    Stos, stera, pamięć globalna i statyczna - program w pamięci systemu.
    Alokacja na stercie a alokacja na stosie
    Polimorfizm w C++ - dlaczego musimy używać wskaźników albo referencji.
6.  Analiza leksykalna programu.
    Implementacja analizatora składniowego.
7.  Wprowadzenie do analizy składniowej gramatyk *LL(1)*.
    Implementacja analizatora składniowego (Parser rekursywnie zstępujący).
    Wprowadzenie do reprezentacji pośredniej programu.
    Tworzenie abstrakcyjnego drzewa składniowego programu.
8.  Wprowadzenie do wzorców projektowych.
    Wzorzec projektowy wizytatora do analizy drzewa składniowego.
    Implementacja klasy przedstawiającej drzewo składniowe w konsoli.
9.  Wprowadzenie do programowania funkcyjnego.
    Refaktoryzacja analizatora składniowego z użyciem paradygmatów funkcyjnych.
10.  Wprowadzenie do interpretacji.
    *REPL* (*Read Evaluate Print Loop*).
    Implementacja pętli *REPL* dla wyrażeń.
11. Tablice symboli.
    Stos jako sposób przekazywania argumentów do funkcji.

## Wymagania

Czego oczekuje się od uczestników:

### Minimum

Wymagana jest znajomość paradygmatów programowania imperatywnego w C++:

* Instrukcje warunkowe (`if`, `if else`).
* Instrukcje pętli (`while`, `for`).
* Struktury (`struct`).
* Jakieś pojęcie czym są wskaźniki (`int*`).
* Tablice (`int[]`).
* Umiejętność poradzenia sobie w swoim środowisku (jak używamy windowsa to umiemy
dodać program do ścieżki tak żeby móc go użyć w terminalu/konsoli).
* Funkcje.
* Typy wyliczeniowe (`enum`).
* Umiejętność i chęć szukania pomocy w internecie 
(prawdopodobnie dokumentacja C++ albo stack overflow).
* Jakieś pojęcie o alokacji dynamicznej (`new` i `delete`).

### Mile widziane

Te pojęcia pojawią się w trakcie koła i będą wytłumaczone, ale
znajomość ich pomoże nam jako prowadzącym, bo prościej będzie
tłumaczyć niektóre zagadnienia (czyli łatwiej też będzie je
zrozumieć).

* `for` na zakresie (`for(auto el: vec)`).
* Czym są metody.
* Referencje (`int&` czym różnią się od wskaźników).
* Pracowanie na linuxie (całość materiałów przygotowywana jest na Ubuntu 18.04).
* Znajomość biblioteki standardowej (`std::vector`, `std::string`, `std::map`...).
* Szablony funkcji (lub klas) w C++ (`template <typename T>`).
* Czym są przestrzenie nazw `namespace my_namespace`.
* Zmienne automatyczne `auto`.
* Wiedza czym są funkcje lambda.
* Wiedza czym jest `move`, l-wartość, r-wartość i referencja na r-wartość (`int&&`).
* Umiejętność używania `const` w odniesieniu do referencji i metod.
