# Bulls and Cows Game

This is a Qt-based implementation of the classic "Bulls and Cows" game, where players try to guess a 4-digit number with no repeating digits. The game provides feedback in terms of "cows" and "bulls" for each guess. A "cow" means a correct digit in the wrong position, while a "bull" means a correct digit in the correct position.

## Project Structure

The project consists of several key components:

- `MainWindow`: The main window of the application, handling user interactions and displaying results.
- `Core`: The core game logic, including generating numbers and calculating scores.
- `Dialog`: A dialog for entering new records.
- `Record`: A dialog for displaying high scores.
- `Retry`: A dialog for retrying the game.

## Getting Started

### Prerequisites

- Qt 6.2.3 or later
- C++17 compatible compiler

### Building the Project

1. **Clone the Repository**:
   ```sh
   git clone <repository-url>
   cd <repository-directory>
   ```

2. **Open the Project in Qt Creator**:
   - Open Qt Creator.
   - Open the `.pro` or `CMakeLists.txt` file from the project directory.

3. **Build the Project**:
   - Configure the project if prompted.
   - Click the build button to compile the project.

4. **Run the Application**:
   - After a successful build, click the run button to execute the application.

## Usage

### Starting a New Game

- Click the "New Game" button to start a new game. This will clear the result table and start a new round.

### Making a Guess

- Enter a 4-digit number with no repeating digits in the input field and click the "Check" button.
- The result table will display your guess and the feedback in terms of cows and bulls.

### Viewing Records

- Click the "Records" button to view the high scores.

### Winning the Game

- If you guess the number correctly, a dialog will prompt you to enter your name if you achieved a high score. You can then choose to start a new game.

## Key Classes and Functions

### MainWindow

- `StartNewGame()`: Clears the result table and starts a new game.
- `Show()`: Updates the result table with the latest guess and feedback.
- `on_Check_clicked()`: Handles the check button click event, validates the input, updates the game state, and displays results.
- `on_NewGame_clicked()`: Handles the new game button click event.
- `on_Records_clicked()`: Handles the records button click event.

### Core

- `NewGame()`: Initializes a new game.
- `SetNum(const std::string&)`: Sets the player's guess.
- `GetNum()`: Returns the current number.
- `GetCows()`: Returns the number of cows for the current guess.
- `GetBulls()`: Returns the number of bulls for the current guess.
- `isWinning()`: Checks if the current guess is the winning guess.
- `IsRecord()`: Checks if the current score is a record.
- `NewRecord(const QString&)`: Records a new high score.

## Contributing

Feel free to contribute to this project by opening issues and submitting pull requests. Any contributions, including bug reports, feature requests, and code improvements, are welcome.
