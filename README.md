# C++ on Linux with VSCode

This is an example of how to use:
* Setting up Visual Studio Code for GCC compiler for C++ applications

## Setting up VSCode
1. Right-click on the project folder, select `Open in Linux` to open the application in WSL2, then type `code .`
2. If prompted to answer "Do you trust the authors of the files in this folder?" check the box "Trust the authors of all files in the parent folder" and click "Yes, I trust the authors."
3. Press Ctrl+Shift+X to open the "Extensions" window.
4. Install the following extensions
    1. C/C++ Themes
    2. C/C++ Extension Pack
    3. Makefile Tools
    4. Remote - WSL
    5. Better C++ Syntax
    6. Clang Format by xaver
5. Close VSCode
6. Install Clang Format with `sudo apt install clang-format`
7. Type `code .` in the terminal to restart it.
8. Press Ctrl+Shift+X again to open the "Extensions" window.
9. If any of the above extensions say "Install in WSL: Ubuntu-22.04", then click that button.
10. Configure editor settings
    1. Click the gear icon in the lower left corner.
    2. Click Settings.
    3. In the search bar, type "minimap" and uncheck "Editor > Minimap: Enabled" where the checkbox says "Controls whether the minimap is shown"
    4. In the search bar, type "Trim Trailing Whitespace" and check the box for "Files: Trim Trailing Whitespace"
    5. In the search bar, type "Detect Indentation" and uncheck the box for "Editor: Detect Indentation"
    6. In the search bar, type "Format On Save" and check the box for "Editor: Format On Save"
    7. In the search bar, type `C_Cpp.clang_format_fallbackStyle`
        1. In the field that appears, change `Visual Studio` to `{ BasedOnStyle: Google, IndentWidth: 4 }`
    8. In the search bar, type "Clang-format: Executable".
        1. In the WSL terminal, type `which clang-format`
        2. Copy that path and paste it into the field.
    9. In the search bar, type "Default Formatter" and select from the dropdown menu `C/C++`.
    10. In the search bar, type `C_Cpp.default.cppStandard` and change the value to `gnu++20`
    11. In the search bar, type `C_Cpp: Intelli Sense`.
        1. For the field `C_Cpp: Intelli Sense Engine`, select `Tag Parser`.
        2. For the field `C_Cpp: Intelli Sense Engine Fallback`, select `enabled`.
    12. In the search bar, type `Render Whitespace`, and select `all`.
11. Set the key bindings to build and clean the solution.
    1. Press Ctrl+K Ctrl+S
    2. In the keybindings search box, type "makefile: build clean the target ALL"
        1. Double-click the keybinding and replace it with Ctrl+Shift+B.
            * There is already a keybinding for that in VSCode, but you can remove the other keybinding to replace it with this.
        2. Press Enter to save the keybinding.
    3. In the keybindings search box, type "Makefile: Build clean the current target"
        1. Double-click the keybinding and replace it with Ctrl+Shift+Z.

## Setting up the dependencies for this project
1. Install `ncurses`
    1. Run this command to install the necessary libraries: `sudo apt install make build-essential lzip m4 libncurses5-dev`

2. Install `gmp`:
    ```
    sudo apt update
    sudo apt install libgmp-dev
    ```

3. Install `pipx` and `gcovr`.
    ```
    sudo apt install pipx
    pipx install gcovr
    ```

4. Install `g++-14` and `gcc-14`.
    ```
    sudo apt install g++-14 gcc-14
    ```

5. Install `openssl` from source, along with the `libssl-dev` library.
    * Install `libz-dev` dependency: `sudo apt install libz-dev`
    * Download the latest version from here: https://www.openssl.org/source/
    * Run the following commands:
    ```
    tar -xzf openssl-x.y.z.tar.gz
    cd openssl-x.y.z
    sudo ./config --prefix=/usr/local/ssl --openssldir=/usr/local/ssl shared zlib
    sudo make
    sudo make install
    sudo apt install libssl-dev
    ```

6. Install `cmake` from source.
    1. Download `cmake-x.y.z.tar.gz` from this link: https://cmake.org/download/
    2. Unzip it with the command `tar -xzf cmake-x.y.z.tar.gz`.
    3. Run the following commands:
        ```
        sudo ./configure
        sudo make
        sudo make install
        ```

7. Set up the badge generator.
    1. Download the Go programming language from this URL, select `Linux`, and download the *.tar.gz file: https://go.dev/doc/install
    2. Install Go by using this command:
    ```
    sudo rm -rf /usr/local/go && sudo tar -C /usr/local -xzf goX.Y.Z.linux-amd64.tar.gz
    ```
    3. Add this line to the `$HOME/.profile`
    ```
    export PATH=$PATH:/usr/local/go/bin
    ```
    4. Restart `wsl`.
    5. Run `go --version` to ensure that Go is installed properly.
    6. Download the dependencies for the badge generator:
    ```
    go mod init generate_badges.go
    go mod tidy
    ```
    7. Compile the generator:
    ```
    go build
    ```

8. Install GoogleTest from source.
    ```
    git clone git@github.com/google/googletest.git -b <latestReleasedTag>
    cd googletest        # Main directory of the cloned repository.
    mkdir build          # Create a directory to hold the build output.
    cd build
    cmake ..             # Generate native build scripts for GoogleTest.
    sudo make
    sudo make install
    ```

9. Install `lcov` from source:
    ```
    git clone git@github.com:linux-test-project/lcov.git -b <latestReleasedTag>
    cd lcov
    sudo make install
    ```