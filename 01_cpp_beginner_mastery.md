# 📘 C++ Beginner Mastery: Zero to Procedural Foundations

> **लक्ष्य:** प्रोग्रामिंग लॉजिक, कंट्रोल फ्लो, फ़ंक्शन्स, बेसिक मेमोरी स्ट्रक्चर और C++ के बुनियादी सिंटैक्स पर ठोस पकड़ बनाना।

---

## 📌 Module B1: Environment Setup & Core Syntax
* **Compiler Architecture & Toolchain:**
  * Source Code (.cpp) $\rightarrow$ Preprocessor $\rightarrow$ Compiler (.s / .o) $\rightarrow$ Linker $\rightarrow$ Executable (.exe / ELF).
  * GCC (`g++`), Clang और MSVC में अंतर।
  * बेसिक कंपाइलेशन फ्लैग्स: `-Wall`, `-Wextra`, `-std=c++20`.
* **Basic I/O Streams:**
  * `<iostream>`, `std::cout`, `std::cin`, `std::cerr`.
  * `std::endl` vs `'\n'` (Buffer Flushes और Performance का अंतर).
  * Fast I/O Tricks: `std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);`.
* **Namespaces:**
  * `namespace` क्यों ज़रूरी हैं?
  * `using namespace std;` को ग्लोबल स्कोप में क्यों **Anti-Pattern (बुरी आदत)** माना जाता है?
  * स्कोप रेजोल्यूशन ऑपरेटर (`::`).

---

## 📌 Module B2: Data Types, Memory Size & Type Systems
* **Primitive Data Types & Memory Footprint:**
  * `bool`, `char` (1 Byte).
  * `short` (2 Bytes), `int` (4 Bytes), `long` / `long long` (8 Bytes).
  * `float` (4 Bytes), `double` (8 Bytes).
  * `sizeof()` ऑपरेटर का सही इस्तेमाल और मेमोरी बाइट्स चेक करना।
* **Signed vs Unsigned Integers:**
  * 2's Complement Representation (पॉजिटिव और नेगेटिव नंबर्स मेमोरी में कैसे बैठते हैं).
  * Integer Overflow और Underflow के खतरे।
* **Type Casting & Modern Safety:**
  * Implicit Conversion (Type Promotion).
  * C-style Cast `(int)x` vs C++ Explicit Casts (`static_cast<int>(x)`).
* **Constants & Modifiers:**
  * `const` कीवर्ड का बुनियादी अर्थ।
  * Modern C++: `constexpr` (Compile-time Constants का परिचय).

---

## 📌 Module B3: Operators & Expressions
* **Arithmetic & Relational Operators:**
  * Pre-increment (`++i`) vs Post-increment (`i++`) का लो-लेवल अंतर (कॉपी बनना बनाम सीधे वैल्यू बढ़ना).
  * Integer Division Trap: `5 / 2 = 2` vs `5.0 / 2 = 2.5`.
* **Logical & Bitwise Operators (Foundations for Low-Level Systems):**
  * Short-circuit evaluation (`&&`, `||`).
  * Bitwise: `&`, `|`, `^`, `~`, Left Shift (`<<`), Right Shift (`>>`).
  * Bitmasking Basics: किसी बिट को Set, Clear और Toggle करना।
* **Ternary Operator:**
  * `condition ? expr1 : expr2` का सही और क्लीन इस्तेमाल।

---

## 📌 Module B4: Control Flow & Logic Building
* **Conditionals:**
  * `if`, `else if`, `else`.
  * `switch-case` स्टेटमेंट और `break`, `default`.
  * C++17 Feature: `if` और `switch` के अंदर इनिशियलाइज़र (`if (int x = getVal(); x > 0)`).
* **Loops (Repetition Structures):**
  * `for` loop (इटरेशन, कंडीशन, इंक्रीमेंट).
  * `while` और `do-while` loops (Entry-controlled vs Exit-controlled).
  * Loop Control: `break` vs `continue`.
  * Nested Loops और 2D ग्रिड्स/पैटर्न्स बनाने का लॉजिक।

---

## 📌 Module B5: Functions & Stack Mechanics
* **Function Fundamentals:**
  * Function Declaration (Prototype) vs Function Definition.
  * Header Files (`.h`) और Source Files (`.cpp`) को अलग-अलग लिंक करना।
  * Return Types और `void`.
* **Execution Stack & Call Frames:**
  * जब कोई फ़ंक्शन कॉल होता है तो CPU Stack Frame में क्या जाता है (Return Address, Local Variables).
  * Stack Overflow क्या है और यह क्यों आता है?
* **Parameter Passing Mechanisms:**
  * **Pass by Value:** डेटा की पूरी कॉपी बनना (मेमोरी और परफॉर्मेंस पेनल्टी).
  * **Pass by Reference (`Type&`):** ओरिजिनल वेरिएबल का उपनाम (Alias) भेजना।
  * **Pass by Const Reference (`const Type&`):** कॉपी रोको और डेटा को रीड-ओनली रखो (इंडस्ट्री स्टैंडर्ड).
* **Function Overloading & Default Arguments:**
  * Name Mangling का बेसिक कॉन्सेप्ट।
  * डिफ़ॉल्ट पैरामीटर्स के नियम।
* **Inline Functions:**
  * `inline` कीवर्ड और Function Call Overhead कम करना।

---

## 📌 Module B6: Arrays, C-Strings & Modern std::string
* **Fixed-size Raw Arrays:**
  * 1D Arrays: डिक्लेरेशन, इनिशियलाइजेशन, और मेमोरी में इंडेक्सिंग (`arr[i] = *(arr + i)`).
  * 2D / Multi-dimensional Arrays: Row-Major Order मेमोरी लेआउट।
  * Array Decay: फ़ंक्शन में एरे पास करने पर उसका पॉइंटर में बदल जाना और साइज खो जाना (`sizeof(arr)` का ट्रैप).
* **Character Arrays vs `std::string`:**
  * C-Strings: Null Terminator (`'\0'`) की अहमियत, Buffer Overflows का खतरा (`gets`, `strcpy`).
  * Modern `std::string`: डायनामिक रीसाइज़िंग, कंकेटीनेशन (`+`), `.length()`, `.substr()`, `.find()`.
  * String Input Tricks: `std::cin >> str` (स्पेस पर रुकना) vs `std::getline(std::cin, str)`.

---

## 📌 Module B7: Beginner Checkpoint & Practical Projects
* [ ] **Self-Assessment Tasks:**
  1. बिटवाइज़ ऑपरेटर का इस्तेमाल करके किसी नंबर का Power of 2 चेक करना।
  2. फ़ंक्शन में एरे पास करके बिना साइज खोए मिनिमम/मैक्सिमम ढूँढना।
  3. `const Type&` और `Type` में मेमोरी कॉपी का फ़र्क प्रैक्टिकली कोड में प्रिंट करना।
* [ ] **Hands-on Console Projects:**
  * **Student Grade & Report Card Manager:** फ़ंक्शन्स, 2D एरेज़ और स्ट्रिंग्स का इस्तेमाल करके।
  * **Tic-Tac-Toe Game (Console):** 2D एरे लॉजिक, विनर-चेकिंग एल्गोरिदम।