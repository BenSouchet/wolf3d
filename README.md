# Wolf3D

Wolf3D is a program developed for my learning course at 42 school.<br/>
The objective of this project is to recreate the principle of ray casting of the famous game Wolfenstein. For this we have to realize in C all necessary functions without using graphic libraries (except the Libmlx library required to create a window on MacOS provided by the 42 school).
<img align="center" src="http://i.imgur.com/SRtIgLN.png" width="100%" />
Several options are available (see [Keyboard shortcuts](https://github.com/Raiden-kazua/Fractol#keyboard-shortcuts) or/and [Mouse controls](https://github.com/Raiden-kazua/Fractol#mouse-controls) sections for more infos) :
* Zoom and unzoom
* Change the number of iterations
* Move the current fractal
* Rotate by step of 90°
* Edit the display gradient
* Navigate between the three fractals
* Edit the shape of the fractal with the position of the mouse (only available with the fractal Julia)

## Install & launch
```bash
git clone https://github.com/BenjaminSouchet/Wolf3D ~/Wolf3D
cd ~/Wolf3D && ./wolf3d maps/good/Maze_Medium.w3d
```
You have to launch the program with a parameter. This is the name of the map you would like open at the execution of the program. This parameter as to be the name of a valid map, below the list of available maps :<br />
maps/good/Basic_00.w3d<br />
maps/good/Basic_01.w3d<br />
maps/good/Maze_Small.w3d<br />
maps/good/Maze_Medium.w3d<br />
maps/good/Maze_Large.w3d<br />

Example :

Open one maze map ⇣
```bash
./fractol maps/good/Maze_Large.w3d
```
## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Reset all the changes made for this map</td>
<td valign="top" align="center"><kbd>&nbsp;clear&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the display gradient (aka change color)</td>
<td valign="top" align="center"><kbd>&nbsp;shift&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Enable or disable the mouse controls</td>
<td valign="top" align="center"><kbd>&nbsp;M&nbsp;</kbd> or <kbd>&nbsp;S&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal (aka zoom)</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal (aka unzoom)</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the up (aka move up)</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the down (aka move down)</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the left (aka width move left)</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the right (aka move right)</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;W&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the numbre of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;Q&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Clockwise rotation on the Z axe</td>
<td valign="top" align="center"><kbd>&nbsp;T&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Counter clockwise rotation on the Z axe</td>
<td valign="top" align="center"><kbd>&nbsp;R&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Display the Julia fractal</td>
<td valign="top" align="center"><kbd>&nbsp;1&nbsp;</kdb></td>
</tr>
<tr>
<td valign="top" height="30px">Display the Mandelbrot fractal</td>
<td valign="top" align="center"><kbd>&nbsp;2&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Display the Tricorn fractal</td>
<td valign="top" align="center"><kbd>&nbsp;3&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;left button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;right button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal (aka zoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal (aka unzoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Contact & contribute
If you want to contact me, or fix / improve Fractol, just send me a mail at **bsouchet@student.42.fr**
