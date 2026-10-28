# 📙 C++ Intermediate Mastery: Pointers, OOP & Core Memory

> **लक्ष्य:** पॉइंटर्स, मैनुअल डायनामिक मेमोरी मैनेजमेंट, OOPs की अंदरूनी कार्यप्रणाली (VTable/VPtr), बेसिक टेम्प्लेट्स और क्लासिक STL का गहरा व्यावहारिक ज्ञान। यह एडवांस C++ (C++11/20/23) का सीधा लॉन्चपैड है।

---

## 📌 Module I1: Pointers & Low-Level Memory Mastery
* **Pointer Foundations:**
  * Address-of Operator (`&`) और Dereference Operator (`*`).
  * पॉइंटर का साइज (32-bit आर्किटेक्चर पर 4 Bytes, 64-bit आर्किटेक्चर पर 8 Bytes).
  * `nullptr` vs `NULL` (0 vs Type-safe Pointer).
* **Pointer Arithmetic:**
  * `ptr + 1` करने पर मेमोरी में क्या होता है (`sizeof(*ptr)` का स्टेप-जंप).
  * पॉइंटर्स का घटाव (Difference between two pointers $\rightarrow$ `ptrdiff_t`).
* **Advanced Pointers:**
  * Pointer to Pointer (`Type**`) - डायनामिक 2D एरेज़ के लिए।
  * `void*` (Generic Pointers) और उनका टाइप-कास्टिंग नियम।
  * Function Pointers: फ़ंक्शन का एड्रेस स्टोर करना और कॉलबैक (Callbacks) पास करना।
* **Memory Traps & Bugs:**
  * **Dangling Pointers:** डिलीट हुई मेमोरी को पॉइंट करना।
  * **Wild Pointers:** अन-इनिशियलाइज़्ड पॉइंटर्स।
  * **Memory Leaks:** बिना `free`/`delete` किए पॉइंटर का स्कोप खत्म होना।
  * **Segmentation Faults:** इनवैलिड एड्रेस या रीड-ओनली मेमोरी को एक्सेस करना।

---

## 📌 Module I2: Stack vs Heap & Dynamic Memory Management
* **Memory Segment Breakdown:**
  * Code Segment (Text) $\rightarrow$ Data Segment (Global/Static) $\rightarrow$ Heap (Dynamic) $\rightarrow$ Stack (Local).
* **Manual Dynamic Allocation (Classic C++):**
  * `new` vs `delete` (सिंगल ऑब्जेक्ट के लिए).
  * `new[]` vs `delete[]` (एरे के लिए - `delete` लगाने पर अनडिफाइंड बिहेवियर क्यों आता है?).
  * C की दुनिया (`malloc`, `calloc`, `realloc`, `free`) vs C++ (`new`/`delete` कंस्ट्रक्टर और डिस्ट्रक्टर को कॉल करते हैं).
* **Placement New Basics:**
  * पहले से मौजूद मेमोरी बफ़र पर ऑब्जेक्ट बनाना (`new (buffer) Type()`).

---

## 📌 Module I3: Object-Oriented Programming (OOP) Under The Hood
* **Classes & Structs:**
  * C++ में `struct` और `class` का इकलौता तकनीकी अंतर (Default `public` vs `private`).
  * Data Hiding, Getters/Setters, Encapsulation.
  * `this` पॉइंटर का आंतरिक काम।
* **The Object Lifecycle (Crucial for RAII):**
  * Default Constructor, Parameterized Constructor.
  * **Initializer Lists (`: member(val)`):** यह कंस्ट्रक्टर बॉडी के अंदर असाइन करने से ज्यादा तेज़ क्यों होती है?
  * **Destructor (`~ClassName()`):** ऑब्जेक्ट के स्कोप से बाहर जाने पर ऑटोमैटिक क्लीनअप का क्रम (रिवर्स ऑर्डर).
* **Copy Semantics (Classic Style):**
  * **Shallow Copy (डिफ़ॉल्ट):** बिटवाइज़ कॉपी, शेयर हुआ हीप पॉइंटर और Double Free क्रैश।
  * **Deep Copy:** कॉपी कंस्ट्रक्टर `ClassName(const ClassName&)` और असाइनमेंट ऑपरेटर `operator=` को हाथ से लिखना (नया बफ़र बनाना).
* **The Rule of Three (Pre-C++11 Standard):**
  * अगर Destructor लिखा है, तो Copy Constructor और Copy Assignment Operator भी खुद लिखने होंगे।

---

## 📌 Module I4: Const-Correctness & References
* **References vs Pointers:**
  * रेफरेंस री-असाइन नहीं हो सकता, नल नहीं हो सकता, और इसका सिंटैक्स क्लीन होता है।
* **Const Pointers Matrix (इंटरव्यू का सबसे पसंदीदा टॉपिक):**
  * `const int* p` $\rightarrow$ डेटा कांस्टेंट है, पॉइंटर बदल सकता है (Pointer to Const).
  * `int* const p` $\rightarrow$ पॉइंटर फिक्स है, डेटा बदल सकता है (Const Pointer).
  * `const int* const p` $\rightarrow$ दोनों फिक्स हैं।
* **Const in Classes:**
  * `const` Member Functions: `int getValue() const;` (ऑब्जेक्ट के स्टेट को बदलने से रोकना).
  * `mutable` कीवर्ड: `const` फ़ंक्शंस के अंदर भी किसी खास वेरिएबल (जैसे कैश/म्यूटेक्स) को बदलने की छूट।

---

## 📌 Module I5: Inheritance, Polymorphism & Virtual Mechanics
* **Inheritance Modes:**
  * `public`, `protected`, `private` इनहेरिटेंस में एक्सेस राइट्स का बदलाव।
  * Base Class Constructor और Derived Class Constructor का एग्जीक्यूशन ऑर्डर।
* **Polymorphism & Virtual Functions:**
  * Compile-time (Early Binding): Function Overloading, Operator Overloading.
  * Run-time (Late Binding): `virtual` कीवर्ड.
* **Under The Hood: VTable & VPtr (इंटरव्यू हॉट-टॉपिक):**
  * कंपाइलर हर पॉलीमॉर्फिक क्लास के लिए Virtual Method Table (VTable) कैसे बनाता है?
  * हर ऑब्जेक्ट के अंदर एक गुप्त `__vptr` (8 बाइट्स) कैसे जुड़ता है?
  * **Virtual Destructors की अनिवार्यता:** बेस क्लास का डिस्ट्रक्टर `virtual` क्यों होना चाहिए (Derived क्लास के मेमोरी लीक को रोकना)?
* **Abstract Classes & Interfaces:**
  * Pure Virtual Functions (`virtual void run() = 0;`).
  * इंटरफ़ेस डिज़ाइन पैटर्न्स।

---

## 📌 Module I6: Foundations of Generic Programming (Templates)
* **Function Templates:**
  * `template <typename T>` का बेसिक सिंटैक्स।
  * Template Instantiation: कंपाइलर अलग-अलग टाइप्स के लिए बैकग्राउंड में अलग-अलग फ़ंक्शंस कैसे कोड जनरेट करता है।
* **Class Templates:**
  * जेनेरिक क्लास बनाना (जैसे एक कस्टम `MyVector<T>` या `Stack<T>`).
* **Multiple Template Parameters:**
  * `template <typename T, typename U>`.

---

## 📌 Module I7: Classic Standard Template Library (STL)
* **Sequence Containers:**
  * `std::vector` (डायनामिक एरे, `.push_back()`, `.capacity()`, `.reserve()`).
  * `std::deque` (डबल-एंडेड क्यू).
  * `std::list` (डबली लिंक्ड लिस्ट).
* **Container Adaptors:**
  * `std::stack` (LIFO).
  * `std::queue` (FIFO).
  * `std::priority_queue` (Max Heap / Min Heap).
* **Associative Containers:**
  * `std::set`, `std::map` (Red-Black Trees, $O(\log N)$ सर्चिंग).
  * `std::unordered_set`, `std::unordered_map` (Hash Tables, $O(1)$ एवरेज सर्चिंग).
* **Iterators:**
  * `iterator`, `const_iterator`, `reverse_iterator`.
  * `it->first`, `it->second` का इस्तेमाल।

---

## 📌 Module I8: Intermediate Checkpoint & Transition to Advanced C++
* [ ] **Self-Assessment Readiness Test:**
  1. क्या आप बिना किसी मेमोरी लीक के रॉ पॉइंटर्स से एक डायनामिक स्ट्रिंग क्लास (`MyString`) बना सकते हैं जिसमें Deep Copy और Rule of Three लगा हो?
  2. क्या आप डायग्राम बनाकर समझा सकते हैं कि `Derived* d = new Derived(); Base* b = d; delete b;` करने पर बेस डिस्ट्रक्टर वर्चुअल न होने से मेमोरी लीक क्यों होता है?
  3. क्या आप VPtr और VTable का मेमोरी साइज (`sizeof`) कैलकुलेट करके दिखा सकते हैं?
* [ ] **Bridge to Modern C++:**
  * अगर ऊपर के तीनों सवालों के जवाब स्पष्ट हैं, तो आप **Module 1 (Modern C++: RAII, Smart Pointers, Move Semantics, Rule of 5/0, Perfect Forwarding, PMR)** के लिए पूरी तरह तैयार हैं।