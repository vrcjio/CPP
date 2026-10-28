# 🚀 Advanced C++ Mastery Syllabus & Roadmap

यह एडवांस C++ सिलेबस मॉडर्न स्टैंडर्ड्स (**C++11 से लेकर C++23**) पर आधारित है. इसे 7 मुख्य मॉड्यूल में बांटा गया है जो कोड की परफॉर्मेंस, मेमोरी मैनेजमेंट और आर्किटेक्चर को मास्टर करने में मदद करेंगे.

---

## 📌 Module 1: Modern Memory Management (आधुनिक मेमोरी मैनेजमेंट)
*मैनुअल मेमोरी हैंडलिंग (`new`/`delete`) को छोड़कर ऑटोमैटिक और सेफ़ रिसोर्स मैनेजमेंट पर ध्यान दें.*

* **1.1 RAII Paradigm (Resource Acquisition Is Initialization)**
  * ऑब्जेक्ट के लाइफटाइम (Lifetime) के साथ रिसोर्स मैनेजमेंट को जोड़ना.
  * कंस्ट्रक्टर (Constructor) में रिसोर्स एक्वायर करना और डिस्ट्रक्टर (Destructor) में रिलीज़ करना.
  * Exception Safety: एरर या एक्सेप्शन आने पर भी रिसोर्स लीक होने से बचाना.
* **1.2 Smart Pointers (C++11/14/17)**
  * **`std::unique_ptr`:** सिंगल ओनरशिप (Exclusive Ownership) और कस्टम डिलीटर्स (Custom Deleters).
  * **`std::shared_ptr`:** शेयर्ड ओनरशिप और रेफरेंस काउंटिंग (Reference Counting) का इंटरनल वर्किंग.
  * **`std::weak_ptr`:** `shared_ptr` के साइक्लिक डिपेंडेंसी (Circular Dependency) को तोड़ना.
* **1.3 Move Semantics & Rvalue References**
  * Lvalue vs Rvalue को गहराई से समझना.
  * Move Constructor और Move Assignment Operator (Rule of 5).
  * `std::move` और `std::forward` का सही उपयोग (Perfect Forwarding).
  * Resource Stealing: बड़े ऑब्जेक्ट्स को बिना कॉपी किए उनका डेटा ट्रांसफर करना.

---

## 📌 Module 2: Modern STL & Ranges (मॉडर्न STL और रेंजेस)
*डेटा प्रोसेस करने के पुराने तरीकों को बदलकर कम कोड और फ़ास्ट एल्गोरिथम का उपयोग करना.*

* **2.1 Advanced Containers & Memory Layout**
  * `std::vector`, `std::array` की Cache Locality और परफॉर्मेंस लाभ.
  * Node-based कंटेनर्स (`std::map`, `std::list`) vs Hash-based कंटेनर्स (`std::unordered_map`).
  * Custom Allocators और PMR (Polymorphic Memory Resources - C++17).
* **2.2 STL Algorithms Mastery**
  * नॉन-मॉडिफाइंग एल्गोरिथम: `std::find_if`, `std::all_of`, `std::any_of`।
  * मॉडिफाइंग एल्गोरिथम: `std::transform`, `std::replace`, `std::copy_if`.
  * रिडक्शन एल्गोरिथम: `std::accumulate`, `std::reduce` (C++17).
* **2.3 Ranges and Views (C++20/23)**
  * `std::ranges` की बुनियादी समझ और Iterators के बिना सीधे कंटेनर पास करना.
  * Pipes (`|`) ऑपरेटर का इस्तेमाल करके लेज़ी इवैल्यूएशन (Lazy Evaluation) करना.
  * `std::views::filter`, `std::views::transform`, और `std::views::take` का कॉम्बिनेशन।
  * `std::ranges::to` (C++23) के ज़रिए व्यूज़ को सीधे वापस कंटेनर में बदलना.

---

## 📌 Module 3: Template Metaprogramming (कंपाइल-टाइम प्रोग्रामिंग)
*रन-टाइम के लोड को कम करने के लिए कंपाइलर से काम करवाना.*

* **3.1 Generic Programming Basics**
  * Function Templates और Class Templates.
  * Full Template Specialization और Partial Template Specialization.
* **3.2 Compile-Time Execution**
  * `constexpr` फंक्शन्स और वेरिएबल्स (C++11/14/17/20).
  * `consteval` (Immediate Functions) और `constinit` (C++20).
  * Type Traits (`<type_traits>` हेडर) और कंपाइल-टाइम पर डेटा टाइप चेक करना.
* **3.3 SFINAE & Modern Constraints**
  * SFINAE (Substitution Failure Is Not An Error) की समझ.
  * `std::enable_if` का पारंपरिक उपयोग.
  * **C++20 Concepts & Constraints:** `requires` क्लॉज के साथ टेम्पलेट कोड को साफ़ और सेफ़ बनाना.
  * Variadic Templates और Fold Expressions (C++17).

---

## 📌 Module 4: Concurrency & Multithreading (कॉनकरेंसी और मल्टीथ्रेडिंग)
*मल्टी-कोर प्रोसेसर की पूरी ताकत का इस्तेमाल करने के लिए पैरेलल कोडिंग.*

* **4.1 Thread Management**
  * `std::thread` की बुनियादी समझ और मूव सिमेंटिक्स.
  * `std::jthread` (C++20): ऑटो-जॉइनिंग (Auto-joining) और को-ऑपरेटिव कैंसिलेशन (Cooperative Cancellation).
  * Lambda expressions को थ्रेड टास्क की तरह इस्तेमाल करना.
* **4.2 Thread Synchronization & Safety**
  * Data Races और Race Conditions को समझना व पहचानना.
  * Mutexes: `std::mutex`, `std::recursive_mutex`, और `std::shared_mutex` (C++17)।
  * Locks: `std::lock_guard`, `std::unique_lock`, और `std::scoped_lock` (C++17 - Deadlock से बचने के लिए).
  * `std::condition_variable` का उपयोग करके थ्रेड्स के बीच सिग्नलिंग करना.
* **4.3 Advanced Concurrency Features**
  * Asynchronous Operations: `std::async`, `std::future`, और `std::promise`.
  * `std::atomic` और Lock-free प्रोग्रामिंग की बुनियादी समझ.
  * Execution Policies (C++17): STL एल्गोरिथम को पैरेलल रन करना (`std::execution::par`).

---

## 📌 Module 5: Compiler Optimization & Performance (परफॉर्मेंस ऑप्टिमाइज़ेशन)
*यह समझना कि C++ कोड बैकग्राउंड में मशीन कोड और हार्डवेयर के साथ कैसे इंटरैक्ट करता है.*

* **5.1 CPU Architecture & Cache Efficiency**
  * Cache Lines, Cache Hits, और Cache Misses को समझना।
  * Data Alignment और Structure Padding।
  * False Sharing और मल्टीथ्रेडेड कोड में इसके नुकसान।
* **5.2 Compiler Control & Optimization**
  * Optimization Flags: `-O1`, `-O2`, `-O3`, `-Ofast` का अंतर।
  * Inline Functions और कंपाइलर का `inline` निर्णय।
  * Loop Unrolling, Vectorization (SIMD) की बुनियादी समझ।
* **5.3 Code Optimization Techniques**
  * Small String Optimization (SSO) और `std::string_view` (C++17) का उपयोग.
  * Copy Elision और RVO (Return Value Optimization) / NRVO।
  * Profiling और Debugging टूल्स: Valgrind, Google Benchmark, AddressSanitizer (ASan).

---

## 📌 Module 6: Design Patterns in C++ (सॉफ्टवेयर डिज़ाइन पैटर्न्स)
*बड़े और स्केलेबल सॉफ्टवेयर प्रोजेक्ट्स को स्ट्रक्चर करने के स्थापित तरीके.*

* **6.1 Creational Patterns (ऑब्जेक्ट निर्माण)**
  * **Singleton Pattern:** थ्रेड-सेफ़ तरीके से लागू करना (Meyer's Singleton)।
  * **Factory Method & Abstract Factory:** ऑब्जेक्ट क्रिएशन लॉजिक को एब्सट्रैक्ट करना।
  * **Builder Pattern:** जटिल ऑब्जेक्ट्स को स्टेप-बाय-स्टेप बनाना।
* **6.2 Structural Patterns (स्ट्रक्चरल डिज़ाइन)**
  * **Adapter Pattern:** दो अलग इंटरफेस वाली क्लासेस को एक साथ जोड़ना।
  * **Decorator Pattern:** बिना इनहेरिटेंस के ऑब्जेक्ट में नई ज़िम्मेदारियाँ जोड़ना।
  * **Facade Pattern:** किसी बड़े सिस्टम के लिए एक आसान इंटरफेस देना।
* **6.3 Behavioral Patterns (बिहेवियरल डिज़ाइन)**
  * **Observer Pattern:** इवेंट-ड्रिवन आर्किटेक्चर (Publish/Subscribe मॉडल)।
  * **Strategy Pattern:** रन-टाइम पर एल्गोरिथम या व्यवहार को बदलना।
* **6.4 Object-Oriented vs Data-Oriented Design (DOD)**
  * कंपोनेंट-बेस्ड आर्किटेक्चर (जैसे गेम इंजन में उपयोग होने वाला Entity Component System - ECS)।

---

## 📌 Module 7: Error Handling & Type Safety (एरर हैंडलिंग और सेफ्टी)
*बिना क्रैश होने वाले और प्रेडिक्टेबल (Predictable) कोड का निर्माण करना.*

* **7.1 Exception Safety Guarantees**
  * No-throw Guarantee (`noexcept` कीवर्ड का सही इस्तेमाल).
  * Strong Exception Guarantee (अगर एरर आए, तो स्टेट पुरानी वाली ही रहे).
  * Basic Exception Guarantee (कोई मेमोरी लीक न हो).
* **7.2 Exceptionless Error Handling (Modern C++)**
  * **`std::optional` (C++17):** ऐसी वैल्यूज के लिए जो शायद मौजूद न हों (Null/Pointer चेक से छुटकारा).
  * **`std::expected` (C++23):** फंक्शन से या तो सही वैल्यू रिटर्न करना या फिर एरर कोड रिटर्न करना (बिना एक्सेप्शन थ्रो किए)।
* **7.3 Modern Type Safety Container**
  * **`std::variant` (C++17):** टाइप-सेफ़ यूनियन (Type-safe union) जो एक समय में कई निश्चित टाइप्स में से एक रख सके.
  * **`std::any` (C++17):** किसी भी टाइप की वैल्यू को सुरक्षित रखने के लिए।
  * `std::get` और `std::holds_alternative` का उपयोग करके वेरिएंट्स को रीड करना।
