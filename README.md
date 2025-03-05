# 42 Fract-ol

<div id="desktop-banner">
<pre>
███████╗██████╗░░█████╗░░█████╗░████████╗░░░░░░░█████╗░██╗░░░░░
██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝░░░░░░██╔══██╗██║░░░░░
█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░█████╗██║░░██║██║░░░░░
██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░░╚════╝██║░░██║██║░░░░░
██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░░░░╚█████╔╝███████╗
╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░░░░░╚════╝░╚══════╝
</pre>
</div>

## 📖 What is `fractol` 🌀?
<details>
<summary><b>A program that generates stunning fractal visualizations</b></summary><br>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Fractol is a project associated with the curriculum of École 42, a coding school known for its project-based learning approach.
The Fractol project uses the C programming language and the MinilibX graphics library to render various types of fractals including Mandelbrot and Julia.
The goal of this project is to teach students about computer graphics, complex number mathematics, optimization techniques, and event-driven programming while creating visually mesmerizing mathematical art.
</p>
</details>

## ✅ Status
<details>
<summary><b>Project completion status</b></summary><br>
<p align="center">
Completed on: 2024-09-07 <br> 110/100</p>
</details>

## 🚀 Usage
To clone and compile:
```shell
git clone https://github.com/Patthh/42_fract-ol.git
cd 42_fract-ol && make
```

To run the program:
```shell
./fractol [fractal_type] [optional_parameters]
```

For example:
```shell
./fractol mandelbrot
./fractol julia 0.285 0.01
```

## ✨ Features
- 🎨 Multiple fractal sets (Mandelbrot, Julia)
- 🖱️ Interactive zoom with mouse wheel
- 🌈 Psychedelic color schemes with dynamic shifting
- 🔍 Precise navigation with keyboard arrows
- 🎮 Interactive Julia set parameter modification
- 🧮 Configurable iteration depth for detail control
* ⭐ Bonus part:
  * The zoom follows the actual mouse position
  * In addition to the zoom: moving the view by pressing the arrows keys.
  * Make the color range shift

> [!WARNING]
> High zoom levels and iteration counts may result in decreased performance

## 🛠️ Implementation Details
<details>
<summary><b>Core Components</b></summary><br>
<p>The Fractol program consists of these main components:</p>

| Component | Description |
|---------|-------------|
| 🎯 MinilibX Integration | Window management and pixel drawing |
| 🧮 Complex Number Math | Calculations for fractal generation algorithms |
| 🔄 Event Handling | Mouse and keyboard input processing |
| 🌈 Color Mapping | Converting iteration values to vibrant color schemes |
| 🖼️ Rendering Engine | Efficient pixel-by-pixel image generation |
| 📏 Viewport Management | Translation, scaling, and boundaries control |

</details>

> [!NOTE]
> "To see a World in a Grain of Sand, And a Heaven in a Wild Flower, Hold Infinity in the palm of your hand, And Eternity in an hour" - William Blake

<div align="center">
  <img src="https://media1.tenor.com/m/T_abp3SBPd0AAAAd/fractal-julia-set.gif" width="400" alt="Fractal Zoom">
  <br>
  <i>A journey into infinite mathematical beauty</i><br><br><br>
</div>

---
<div align="center">
  <p>Made with ❤️ and lots of 🧠</p>
</div>
