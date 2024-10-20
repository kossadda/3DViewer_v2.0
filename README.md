<a id="readme-top"></a>

 | [![Contributors][contributors-shield]][contributors-url] | [![Forks][forks-shield]][forks-url] | [![Stargazers][stars-shield]][stars-url] | [![Issues][issues-shield]][issues-url] | [![MIT License][license-shield]][license-url] | [![LinkedIn][linkedin-shield]][linkedin-url] |

<br />
<div align="center">
  <a href="https://github.com/emmonbear/3DViewer">
    <img src=".misc/images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">3DViewer</h3>

  <p align="center">
    <br />
    <a href="https://github.com/emmonbear/3DViewer"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/emmonbear/3DViewer">View Demo</a>
    /
    <a href="https://github.com/emmonbear/3DViewer/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    /
    <a href="https://github.com/emmonbear/3DViewer/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>


<details>
  <summary><strong>Table of Contents</strong></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#uml-class-diagram">UML class diagram</a></li>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#required-software">Required software</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>


## About The Project

![Appearance](./misc/images/program.png) <br>

The goal of this project is to implement a program for viewing 3D models in wireframe form (3D Viewer) in the C++ programming language. The models themselves are loaded from .obj files, which makes it possible to view them on the screen with the ability to rotate, scale and move.

- The program is developed in the C++ standard language using the gcc compiler. Additional libraries and Qt modules are used;
- The program code is located in the src folder;
- The program and test build is configured using CMake, which is launched using Makefile with a standard set of targets for a GNU program: all, install, uninstall, clean, dvi, dist, tests. Installation is carried out in the bin folder in the repository root;
- The program is developed in accordance with the principles of object-oriented programming. The following development patterns are used: Facade, Singleton, Strategy, MVC;
- The code is written in accordance with Google Style;
- The modules related to model loading and affine transformations are covered by unit tests;
- The program displays only one model on the screen at a time;
- The program allows you to:
    - Load a wireframe model from an `obj` file (supports only a list of vertices and surfaces);
    - Move the model a given distance relative to the `X`, `Y`, `Z` axes;
    - Rotate the model a given angle relative to its `X`, `Y`, `Z` axes;
    - Scale the model by a given value;
    - Perform affine transformations using the processor/video memory;
    - Set up the projection type (parallel and central);
    - Set up the edge type (none, solid, dotted), color and thickness;
    - Set up the vertex type (none, circle, square), color and size;
    - Choose a background color;
    - Save the resulting ("rendered") images to a file in the `bmp` and `jpeg` formats;
    - Record small "screencasts" - current user affine transformations of the loaded object into `gif`-animation (640x480, 10`fps`, 5s);
- The program has a graphical user interface based on the GUI libraries `QT` with `API` for `C++`.
- The graphical user interface contains:
    - A button for selecting a file with a model and a field for entering/outputting its name;
    - A button for switching the affine transformation method (processor/video card);
    - A button for switching the projection;
    - Buttons for selecting the type, color and thickness of edges;
    - Buttons for selecting the type, color and size of vertices;
    - A button for selecting a background;
    - Buttons for saving an image and a screencast;
    - A wireframe model visualization area;
    - Sliders and input fields for moving the model;
    - Sliders and input fields for rotating the model;
    - Slider and input field for scaling the model;
- Information about the loaded model - file name, number of vertices and edges.
- Settings are saved between program restarts;
- Implementation class inside the `s21` namespace;

### UML class diagram

![Appearance](./misc/images/uml_diagram.png) <br>


<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

<p align="center">
  <p>
    <a href="https://www.cplusplus.com/">
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" width="80" height="30">
    </a>
    <a href="https://cmake.org/">
      <img src="https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white" width="80" height="30">
    </a>
    <a href="https://www.qt.io/">
      <img src="https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white" width="80" height="30">
    </a>
    <a href="https://www.opengl.org/">
      <img src="https://www.opengl.org/img/opengl_logo.jpg" width="80" height="30">
    </a>
  </p>
</p>

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Getting Started

To get a local copy and run it, follow these steps.

### Required software

* CMake
  ```
  sudo apt install cmake
  ```

* Qt
  ```
  sudo apt install qt6-base-dev
  ```

* OpenGL
  ```
  sudo apt-get install build-essential libgl1-mesa-dev
  ```

### Installation

1. Install the required software (if missing)
2. Clone the repository
    ```sh
    git clone git@github.com:emmonbear/3DViewer.git
    ```
3. Run the installation program
    ```sh
    make install
    ```
4. Run the program manually (`3DViewer/bin/viewer`) or enter the command
    ```
    make run
    ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Contributing:

<a href="https://github.com/emmonbear/3DViewer/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=emmonbear/3DViewer" alt="contrib.rocks image" />
</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Contact

Pervin Gabilov - [Telegram](https://t.me/kossadda) / [e-mail](gabiov1997@gmail.com)

Ilya Moskalev  - [Telegram](https://t.me/emmonbea) / [e-mail](moskaleviluak@icloud.com)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ССЫЛКИ И ИЗОБРАЖЕНИЯ MARKDOWN -->
[contributors-shield]: https://img.shields.io/github/contributors/emmonbear/3DViewer.svg?style=for-the-badge
[contributors-url]: https://github.com/emmonbear/3DViewer/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/emmonbear/3DViewer.svg?style=for-the-badge
[forks-url]: https://github.com/emmonbear/3DViewer/network/members
[stars-shield]: https://img.shields.io/github/stars/emmonbear/3DViewer.svg?style=for-the-badge
[stars-url]: https://github.com/emmonbear/3DViewer/stargazers
[issues-shield]: https://img.shields.io/github/issues/emmonbear/3DViewer.svg?style=for-the-badge
[issues-url]: https://github.com/emmonbear/3DViewer/issues
[license-shield]: https://img.shields.io/github/license/emmonbear/3DViewer.svg?style=for-the-badge
[license-url]: https://github.com/emmonbear/3DViewer/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
