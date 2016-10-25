# Wolf3D

Wolf3D is a program developed for my learning course at 42 school.<br/><br/>
The objective of this project is to recreate the principle of ray casting of the famous game Wolfenstein.<br/>
For this we have to realize in C all necessary functions without using graphic libraries (except the Libmlx library required to create a window on MacOS provided by the 42 school).<br/><br/>
PS : This game has not a real goal, you can simply explore the mazes.<br/><br/>
<img align="center" src="http://i.imgur.com/IhvdtKf.jpg" width="100%" />
Several options are available (see [Keyboard shortcuts](https://github.com/BenjaminSouchet/Wolf3D#keyboard-shortcuts) or/and [Mouse controls](https://github.com/BenjaminSouchet/Wolf3D#mouse-controls) sections for more infos) :
* Move in any directions (sideways movements included)
* Rotation with keys (or mouse position)
* Textured Mode (with floor and ceil casting)
* Walls collision (with an slight realistic offset)
* Minimap with rotation according to the player rotation
* Fire Torch Lighting simulation (in Normal & Hardcore Mode only)
* Several songs (with Selection of track / Play / Pause and Stop options)
* Hardcore Mode & Easy Mode
* Ambient occlusion

## Install & launch
```bash
git clone https://github.com/BenjaminSouchet/Wolf3D ~/Wolf3D
cd ~/Wolf3D && ./wolf3d maps/good/Maze_Medium.w3d
```
You have to launch the program with a parameter. This is the name of the map you would like open at the execution of the program. This parameter as to be the name of a valid map, below the list of available maps :<br />
*maps/good/Basic_00.w3d*<br />
*maps/good/Basic_01.w3d*<br />
*maps/good/Maze_Small.w3d*<br />
*maps/good/Maze_Medium.w3d*<br />
*maps/good/Maze_Large.w3d*<br />

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
<td valign="top" height="30px">Reset all the changes made</td>
<td valign="top" align="center"><kbd>&nbsp;clear&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Hold to run faster</td>
<td valign="top" align="center"><kbd>&nbsp;shift&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Enable or disable the mouse controls</td>
<td valign="top" align="center"><kbd>&nbsp;M&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step forward</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step backward</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step to the left</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step to the left</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Switch to the first song</td>
<td valign="top" align="center"><kbd>&nbsp;1&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Switch to the second song</td>
<td valign="top" align="center"><kbd>&nbsp;2&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Switch to the third song</td>
<td valign="top" align="center"><kbd>&nbsp;3&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Switch to the fourth song</td>
<td valign="top" align="center"><kbd>&nbsp;4&nbsp;</kbd></td>
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
<span style="width:70px">&nbsp;</span><strong>Action</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Change the view according to the mouse position in the window</td>
<td valign="top" align="center"><kbd>&nbsp;Move the cusor in the window&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Rotate to the left</td>
<td valign="top" align="center"><kbd>&nbsp;Stay the cursor in left side of the window&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Rotate to the right</td>
<td valign="top" align="center"><kbd>&nbsp;Stay the cursor in right side of the window&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Contact & contribute
If you want to contact me, or fix / improve Fractol, just send me a mail at **bsouchet@student.42.fr**
