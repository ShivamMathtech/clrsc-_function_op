
````markdown
# `clrscr()` Function in C

## 📌 Overview
The `clrscr()` function is used to clear the output screen in C programming.  
It is **not part of the standard C library** — instead, it is defined in **`conio.h`**, which is a **non-standard** header available primarily in **Turbo C, Borland C, and some DOS-based compilers**.

**Modern compilers like GCC or Clang do not support `clrscr()`** by default, and alternative methods must be used.

---

## 📚 Syntax
```c
#include <conio.h>

void clrscr(void);
````

* **Return Type:** `void` (no return value)
* **Parameters:** None
* **Effect:** Clears the console screen and moves the cursor to the top-left corner (position 0,0).

---

## ⚠️ Limitations

* Works only in **DOS-based** environments.
* Not portable to **modern compilers** like GCC on Linux/Mac.
* For **Windows/Linux**, alternative approaches are required.

---

## 💻 Example

```c
#include <conio.h>
#include <stdio.h>

int main() {
    printf("Hello, World!");
    getch(); // Wait for a key press
    clrscr(); // Clear the screen
    printf("Screen cleared!\n");
    getch(); // Wait again before closing
    return 0;
}
```

---

## 🚀 Advanced Alternatives for Modern Compilers

Since `clrscr()` is not available in GCC/Clang, you can use these approaches:

### **1. Using `system()` Command**

```c
#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear"); // Linux / Mac
#endif
}

int main() {
    printf("Hello, World!\n");
    getchar();
    clearScreen();
    printf("Screen cleared!\n");
    return 0;
}
```

### **2. Using ANSI Escape Codes**

```c
#include <stdio.h>

void clearScreenANSI() {
    printf("\033[2J\033[H"); // Clear screen & move cursor to top-left
}

int main() {
    printf("Hello, World!\n");
    getchar();
    clearScreenANSI();
    printf("Screen cleared using ANSI!\n");
    return 0;
}
```

**Advantages of ANSI Method:**

* Portable across Linux, macOS, and Windows (with ANSI support enabled).
* No need for `system()` calls.

---

## 🧠 Hidden Facts & Patterns

* `clrscr()` **internally uses BIOS or DOS interrupts** in old compilers.
* The cursor position after `clrscr()` is always `(0,0)`.
* Combining `clrscr()` with `gotoxy(x, y)` allows advanced text-based UI designs.
* In modern terminal handling, `ncurses` library is preferred for screen control.

---

## 📜 Summary

| Feature       | `clrscr()` | ANSI Codes | `system()`                   |
| ------------- | ---------- | ---------- | ---------------------------- |
| Portability   | ❌ No       | ✅ Yes      | ⚠️ Limited                   |
| Speed         | ✅ Fast     | ✅ Fast     | ❌ Slow                       |
| Standard      | ❌ No       | ✅ Yes      | ✅ Yes                        |
| Security Risk | None       | None       | **High** (due to `system()`) |

---

## 🔗 References

* [Turbo C++ Documentation](https://en.wikipedia.org/wiki/Turbo_C%2B%2B)
* [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code)
* [ncurses Library](https://invisible-island.net/ncurses/)

  ## By Shivam Singh

```

```
