## ChessEngine
My chess engine, written in C++, is a project born out of a passion for chess and a desire to explore the world of chess programming. Leveraging techniques learned from resources like the Chess Programming Wiki, it aims to simulate the intelligence of a human chess player. It supports UCI protocol. 
## Motivation 
I began this project because of my interest in chess. After watching [Sebastian Lague's video](https://www.youtube.com/watch?v=U4ogK0MIzqk&t=646s&ab_channel=SebastianLague) on building a chess engine in C#, I felt inspired and dove into learning about chess programming. I stumbled upon this [page](https://www.chessprogramming.org/) and started absorbing as much knowledge as I could. I made the decision to write my engine in C++ because I believe it offers the best performance for this kind of project. As I progressed with my project, I encountered numerous challenges and breakthroughs, from implementing efficient board representations to optimizing move generation and search algorithms. Overall, my journey into chess engine development has been a thrilling adventure, fueled by passion and curiosity.
## Features
### Search
- Iterative Deepening
- Negamax
- Transposition Table
- Move ordering
- MVV-LVA
- Perfit
- Polybook
- Quiesence
### Board
- Bitboards
- Mailbox move generation
- Zobrist Hashing
- UCI support
### Evaluation
- Pawn Structure
- Material
- Piece-Square Tables
- Bitboards masks

## How to build it
1. Clone the Repository:If you haven't already done so, clone your project repository to your local machine using Git. Open Command Prompt or Git Bash and run:
```cmd
git clone https://github.com/Zacharay/chessEngine.git
```
2. Create a Build Directory:Navigate into the directory of your project and create a directory to store the build files. This keeps your source directory clean:
```cmd
mkdir build
cd build
```
3. Run CMake:Once inside the build directory, run CMake to generate the build files. Specify the path to the directory containing your CMakeLists.txt file (usually the root directory of your project). Open Command Prompt or Git Bash and run:
```cmd
cmake ..
```
4. Build and Run the Project
```cmd
make
./chessEngine 
```

