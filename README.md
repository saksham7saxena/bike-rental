# Bike Rental System

![C++](https://img.shields.io/badge/Language-C++17-blue.svg)
![Build](https://img.shields.io/badge/Build-CMake-green.svg)

A high-performance, modular C++ application designed for efficient bike rental management. This system provides a robust CLI interface for tracking inventory, managing rider database, and simplifying the rental transaction process with automated pricing and state management.

## 🚀 Key Features

*   **Smart Inventory Management**: Track bike status real-time (`Available`, `Rented`, `Maintenance`) to prevent double-booking.
*   **Dynamic Pricing Engine**: Automated cost calculation based on bike type (`Standard` vs `Premium`) and rental duration.
*   **Persistent Storage**: Reliable CSV-based database system ensures data is saved between sessions without complex SQL dependencies.
*   **Modular Architecture**: Built with clean, separation-of-concerns principles using modern C++17 standards.
*   **Analytics Dashboard**: Integrated revenue tracking and active rental monitoring.

## 🛠️ Tech Stack

*   **Language**: C++17
*   **Build System**: CMake
*   **Data Format**: CSV (Comma-Separated Values)
*   **Interface**: Command Line Interface (CLI)

## 📦 Installation & Usage

### Prerequisites
*   C++ Compiler (GCC, Clang, or MSVC)
*   CMake (Version 3.10 or higher)

### Build Instructions

1.  **Clone the Repository**
    ```bash
    git clone https://github.com/yourusername/bike-rental.git
    cd bike-rental
    ```

2.  **Compile with CMake**
    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

3.  **Run the Application**
    *   **Linux/macOS**: `./BikeRentalSystem`
    *   **Windows**: `Debug\BikeRentalSystem.exe`

## 📂 Project Structure

```bash
bike-rental/
├── data/               # Persistent CSV database
│   ├── bikes.csv
│   ├── riders.csv
│   └── rentals.csv
├── include/            # Header files (Interface)
├── src/                # Source files (Implementation)
├── legacy/             # Archive of previous versions
├── CMakeLists.txt      # Build configuration
└── README.md
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
