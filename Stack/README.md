# Stack Implementation in C++

This project demonstrates a simple stack implementation in C++. A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This means the most recently added element is the first to be removed. The stack operations include checking if the stack is full or empty, adding (pushing) and removing (popping) elements, peeking at the top element, displaying all elements, and counting the total number of elements.

## Functions Overview

1. **`isEmpty(int top)`**  
   - **Description**: Checks if the stack is empty by verifying if `top` equals `-1`. Returns `1` (true) if the stack is empty and `0` (false) otherwise.
   - **Purpose**: Ensures that operations like `pop` and `peek` only proceed if there are elements in the stack.

2. **`isFull(int top)`**  
   - **Description**: Checks if the stack is full by comparing `top` with the maximum index (in this case, `4`, meaning the stack holds up to 5 elements).
   - **Purpose**: Ensures no further elements are pushed when the stack reaches its capacity.

3. **`push(int val, int &top, int arr[])`**  
   - **Description**: Adds an element `val` to the top of the stack if there’s space available. First, it checks if the stack is full; if not, it increments `top` and stores `val` at `arr[top]`.
   - **Purpose**: This is the core function for adding new elements to the stack.

4. **`pop(int &top, int arr[])`**  
   - **Description**: Removes the top element from the stack. It first checks if the stack is empty; if not, it removes the element at `arr[top]`, resets its value to `0`, and decrements `top`.
   - **Purpose**: Essential for removing elements from the stack in LIFO order.

5. **`peek(int arr[], int top)`**  
   - **Description**: Displays the top element without removing it from the stack. Checks if the stack is empty first, then shows `arr[top]` if not.
   - **Purpose**: Useful for viewing the last added element in the stack.

6. **`display(int arr[], int length)`**  
   - **Description**: Outputs all elements in the stack from top to bottom. Checks if the stack is empty before displaying each element from `arr[length]` down to `arr[0]`.
   - **Purpose**: Allows users to view the full contents of the stack.

7. **`count(int top)`**  
   - **Description**: Shows the current number of elements in the stack by displaying `top + 1`. If the stack is empty, it reports "0 elements."
   - **Purpose**: Helpful for tracking how many elements are in the stack at any time.

---

### About the Code
This code was written by **Omar**. For questions or suggestions, feel free to reach out via Telegram: [Dev3mora](https://t.me/Dev3mora).

*This README was generated with the assistance of AI. (ChatGPT)*
