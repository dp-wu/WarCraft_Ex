# OJ005:WarCraft1


## **Source:**
This is one of the OJ project: http://cxsjsxmooc.openjudge.cn/2020t3spring3/005/?lang=en_US


## **Description:**

There are two tribes in the world. The headquarter of Red tribe is in the west of the world and the Blue tribe’s is in the east. There are n cities between these two headquarters, denoted as: <br />
    ***Red headquarter -City 1 - City 2 - City 3, …  - City n -Blue headquarter*** <br />
<br />
Headquarters can create warriors. There are five types of warriorsin total. They are dragon, ninja,iceman, lion, wolf. Every warrior has three properties: Number, strength, Attack. <br />
<br />
In each headquarter, the Number of warriors starts from 1. For example, The Number of the warrioris n, if he was the Nth to be made in Red headquarter. Similarly, If the Blue headquarter made the Nth warrior, his Number is n. <br />
<br />
Every warrior is born with a strength. <br />
<br />
In every integral point, each headquarter will create a new warrior. <br />
The order of warrior creation in Red headquarter: iceman, lion, wolf, ninja, dragon. <br />
The order of warrior creation in Blue headquarter: lion, dragon, ninja, iceman, wolf. <br />
<br />
The creation of a warrior will consume the strength of the headquarter. For example, if the Blue headquarter made a warrior with m strength, then the strength of the Blue headquarter will reduce m. <br />
<br />
If the headquarter doesn’t have the enough strength to create the present warrior,it will move to the warrior of next type. When the headquarter cannot create any type of warriors, it stops. <br />
<br />


## **Requirement:**

When the time and the initial strength of two headquarters are given, you need to list every event of two headquarters after 0:00. <br />
There are two types of events: <br />
***(1)  A warrior is born*** <br />
Sample:  004 blue lion 5 bornwith strength 5,2 lion in red headquarter <br />
It means in 4:00, a lion was born in red headquarter, his Number is 5 and strength is 5. Now, there are 2 lions in the red headquarter.(notice: do not use plural form, for example it is 2 lionnot 2 lions) <br />
***(2)  headquarter stops making warriors*** <br />
Sample: 010 red headquarter stops making warriors <br />
It means in 10:00, the red headquarter stops making warriors <br />
<br />
 
When you list the events, it should output in chronological order. If some events happen at the same time, first output the event in the Red headquarter then Blue headquarter.<br />
<br />


## **I/O:**

***Input:***<br />
The first line is an integer, it means the number of test cases.<br />
For every case:<br />
The first line is an integer M, it means the initial strength of the two headquarters.<br />
The second line are the strength of dragon, ninja, iceman, lion, wolf.<br />


***Output:***<br />
For every case:<br />
You need to output every event starting from 0:00 until the two headquarters stop creating warriors.<br />
First output “Case:n”, n is the number of the case, n is starting from 1 (The total number of cases is given in the first line of input).<br />
Every event start with the timing, the timing is three-digit number (there is no 24 hours limited).<br />
<br />

## **Sample I/O:**
***Input:***
```
1
20
3 4 5 6 7
```
***Output:***
```
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
```
