# ❌ Tic Tac Toe — C++ Console Game

A console-based Tic Tac Toe game in C++ with two modes — Player vs Player and Player vs Computer.

---

## 🎮 Game Modes

| Mode | Description |
|------|-------------|
| Player vs Player | Two humans take turns on the same machine |
| Player vs Computer | Play against a computer making random moves |

---

## 🕹️ How to Play

- The board has positions numbered **1 to 9**:
```
 1 | 2 | 3
 4 | 5 | 6
 7 | 8 | 9
```
- Player 1 is **X**, Player 2 / Computer is **O**
- Enter a position number on your turn
- First to get **3 in a row** (horizontal, vertical, or diagonal) wins
- If all 9 squares are filled with no winner → **Draw**

---

## 📁 Repository Structure

```
TicTacToe-Cpp/
│
├── src/
│   └── TicTacToe.cpp       # Main game logic
│
├── README.md
└── .gitignore
```

---

## 🛠️ Tech Used

- **C++** — core language
- `cstdlib` + `ctime` — random move generation for computer
- Console I/O with `cin` / `cout`

---

## 🚀 How to Run

**1. Clone the repository**
```bash
git clone https://github.com/asgeek96/TicTacToe-Cpp.git
cd TicTacToe-Cpp/src
```

**2. Compile**
```bash
g++ TicTacToe.cpp -o TicTacToe
```

**3. Run**
```bash
./TicTacToe
```

> On Windows: `TicTacToe.exe`

### Example Output
```
==========================
   Welcome to Tic Tac Toe
==========================

Main Menu:
  1. Player vs Player
  2. Player vs Computer
  3. Exit

 1 | 2 | 3
 4 | 5 | 6
 7 | 8 | 9

Player 1 (X), enter position (1-9): 5
```

---

## 💡 What I Learned

- 2D game logic using a 1D array in C++
- Win detection across rows, columns, and diagonals
- Separating game functions (display, mark, checkWin)
- Building a menu-driven loop with `switch` statements
- Random move generation for a basic computer opponent

---

## 👤 Author

**Anubhav Srivastava**
[GitHub](https://github.com/asgeek96) · [LinkedIn](https://www.linkedin.com/in/asgeek)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
