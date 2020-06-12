## **Description:**

There are two tribes in the world. The headquarter of Red tribe is in the west of the world and the Blue tribe’s is in the east. There are n cities between these two headquarters, denoted as: <br />
Red headquarter -City 1 - City 2 - City 3, …  - City n -Blue headquarter

 

Headquarters can create warriors. There are five types of warriorsin total. They are dragon, ninja,iceman, lion, wolf. Every warrior has three properties: Number, strength, Attack.

 

In each headquarter, the Number of warriors starts from 1. For example, The Number of the warrioris n, if he was the Nth to be made in Red headquarter. Similarly, If the Blue headquarter made the Nth warrior, his Number is n.

 

Every warrior is born with a strength.

 

In every integral point, each headquarter will create a new warrior.

The order of warrior creation in Red headquarter: iceman, lion, wolf, ninja, dragon

The order of warrior creation in Blue headquarter: lion, dragon, ninja, iceman, wolf

 

The creation of a warrior will consume the strength of the headquarter. For example, if the Blue headquarter made a warrior with m strength, then the strength of the Blue headquarter will reduce m.

 

If the headquarter doesn’t have the enough strength to create the present warrior,it will move to the warrior of next type. When the headquarter cannot create any type of warriors, it stops.

 

## **Requirement:**

When the time and the initial strength of two headquarters are given, you need to list every event of two headquarters after 0:00.

There are two types of events:

(1)  A warrior is born

Sample:  004 blue lion 5 bornwith strength 5,2 lion in red headquarter

It means in 4:00, a lion was born in red headquarter, his Number is 5 and strength is 5. Now, there are 2 lions in the red headquarter.(notice: do not use plural form, for example it is 2 lionnot 2 lions)

(2)  headquarter stops making warriors

Sample: 010 red headquarter stops making warriors`

It means in 10:00, the red headquarter stops making warriors

 

When you list the events, it should output in chronological order. If some events happen at the same time, first output the event in the Red headquarter then Blue headquarter.

 

## **I/O:**


***Input:***
The first line is an integer, it means the number of test cases.
For every case:
The first line is an integer M, it means the initial strength of the two headquarters.
The second line are the strength of dragon, ninja, iceman, lion, wolf.


***Output:***
For every case:
You need to output every event starting from 0:00 until the two headquarters stop creating warriors.
First output “Case:n”, n is the number of the case, n is starting from 1 (The total number of cases is given in the first line of input).
Every event start with the timing, the timing is three-digit number (there is no 24 hours limited).
