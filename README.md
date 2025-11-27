## Overview

During my summer breaks in university, I wanted to apply my academic knowledge and build something challenging. I developed a smart electric skateboard.

# smart-wheels
Electric skateboard with sensors The project that improving over time.

Achievements:

•	Building skateboard

•	Make it electricity sate board

•	Knowing how to program it with Arduino

•	Building  RC with Arduino 

Next goals:

•	Test the brake algorithm on the field.

•	Test the help turn algorithm.

•	Write an algorithm to move around small obstacles.


After a long time that I have been working as a technician of UAVs I discided to see if I can get into the world of robotics by myself and build a robot .so I decided to start with trying to build an electrical skateboard. At first, I was sketching and deciding what I need to buy for this project. So I started with the purpose of what is needed to do, I wanted that the skateboard will be able to skate fast on multiple kinds of field & conditions and not only solid roads (like grass, soft sands, little rocks, low stairs…). So for that, I needed a big board with a strong shield and axis and shock absorber. At that point in life, I didn’t have too much money to spend so I've been efficient as much as I could with the spending. The best place to buy all of this material was Aliexpress, there I compered etch part of the board by his descriptions and size details, eventually after a long time most of the part arraived.

  <img align="right" width="300" height="300" src="https://user-images.githubusercontent.com/92687493/138551576-cb38a095-64db-49fc-9dc6-0be1b4fc92c4.jpg">
 
 <img src="https://user-images.githubusercontent.com/92687493/138551563-073b41c3-3ce6-48ae-9800-12b308d40024.jpg"  width="300" height="300" />

The board was needed to be with a foot holder(like a snowboard) cause after I calculate the max speed(approx.) in a site that you put details of the engine power & battery and spin ratio I saw that it could get to 55 km/h and its very fast for skating. Also by knowing that I would work with a current up to 90 amp(from the period of the technician).I needed a good castle 

Castle: Phonix 160 edge HV 

Motor: AXI gold line( I made adjustments there for my tools with a friend that have a CNC machine)

  <img align="right" width="300" height="300" src="https://user-images.githubusercontent.com/92687493/138551598-e56c6a7c-97ca-4b4a-9046-851a957e1efd.jpg">
 <img src="https://user-images.githubusercontent.com/92687493/138551607-b6f87611-20d1-48b7-8ff3-22fa7aaafb69.jpg"  width="300" height="300" />

For the communication with the  castle, I order a normal RC with a receiver for electric skateboard from Aliexpress and cause my castle doesn’t know to change the  direction of the current (usually castle for electric skateboard knows) I did some adjustments with the remote controller

<img align="right" width="300" height="300" src="https://user-images.githubusercontent.com/92687493/138551632-498b3626-b7f1-483a-a8c5-372f773b35e2.jpg">
 <img src="https://user-images.githubusercontent.com/92687493/138551640-780d0bb8-6a13-44e4-9c74-b126f5b48305.jpg"  width="300" height="300" />

Then I needed to plan how the circuit is gonna be, because I had one battery(42V) and two castles & motors so from understanding how the current needs to flow I soldered the wires in a parallel circuit structure.

 <img src="https://user-images.githubusercontent.com/92687493/138551658-6588201f-2bfd-4336-995d-622286e7639b.jpg"  width="300" height="300" />


So I connect all the "parts" that I had(there were a lot of adjustments and creativity) and after a couple of fails, it finely worked.

https://www.youtube.com/watch?v=NxOkIISRPyA&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

Then test out of the field and annoying my dog.

1)https://www.youtube.com/watch?v=HbVKZ9eH_eY&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

2)https://www.youtube.com/watch?v=-wr1UYbVGY8&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

Test with me on it. 

https://www.youtube.com/watch?v=CuGA61hx5Hg&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

make some braking and more complex tests with a friend that wearing protectors equipment.

https://www.youtube.com/watch?v=WvDeFf17qHQ&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

At the last video i noted that it could be very vast so I decided to change the ratio of the teeth wheel transsmition between the engine and wheels to get more moment and less speed (by decreasing the number of teeth on the engine tooth wheel transsmiter.) 

 <img src="https://user-images.githubusercontent.com/92687493/138551671-cd14ec32-f719-47bc-b4cc-da37d43ce402.jpg"  width="300" height="300" />

Then I took it for a 4 km ride around my house and it worked perfectly.

https://www.youtube.com/watch?v=k2RkIn_Q67Q&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

Then I decided to build a charger for my 42V lithium battery(cause after exploring about that I saw it could be much more cheaper and also I like to learn new things).
For this, I asked my neighbor for help(cause he understand more than me about electricity), at the beginning, we understand the structure of my battery and how it wired. Then I understood, according to forums, that the lithium battery charger needs to stabilize each cell simultaneity while charging so I needed to adapt for that the right BMS. After a lot of exploring and right soldering each wire, we also seceded to build it properly.

<img align="right" width="200" height="300" src="https://user-images.githubusercontent.com/92687493/138551687-01de3417-f2bc-4115-b370-9cfafa85cccd.jpg">
<img align="left" width="200" height="300" src="https://user-images.githubusercontent.com/92687493/138551692-3a2a04b5-117c-4f49-a526-831ca8eb4f8c.jpg">
<p align="center">
  <img width="200" height="300" src="https://user-images.githubusercontent.com/92687493/138551682-dcffc2de-0aaa-4939-b68d-e6aaa579621f.jpg">
</p>


<img align="left" width="250" height="300" src="https://user-images.githubusercontent.com/92687493/138551699-1565a9a3-e272-4768-a0a7-108d2ff47fa4.jpg">
<p align="center">
  <img width="250" height="300" src="https://user-images.githubusercontent.com/92687493/138551695-82da27d3-fdc2-4446-992d-e617800c037c.jpg">
</p>
 
In the year 2021, I learned at the university programing in python and Matlab, so I wanted to use this knowledge and make this skateboard into a smart robot that can detect obstacles and operate as well for safety. For that, I understand the best way is to program it is with Arduino and sensors.
So in the beginning, I needed to learn how Arduino code work(c++) and how is the structure code should be. At first, I dealing with LEDs 

https://www.youtube.com/watch?v=e59bhPRiEkc&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

To understand more I combined two sensors: distance & LCD

https://www.youtube.com/watch?v=qHsClQXByfI&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

After some testing my old receiver tried to make problems and stop to work so then I needed to change all the RC chips to Arduino chips and get the right data for my project by wifi.

<img align="right" width="380" height="300" src="https://user-images.githubusercontent.com/92687493/138551734-270ba945-9af1-43d6-8594-c3f29fa4d586.jpg">
<img src="https://user-images.githubusercontent.com/92687493/138551744-1c3f47dc-3ed4-4b4c-b868-bd4b900e845f.jpg"  width="300" height="300" />



For the first time after a lot failiersit worked and contained different algorithms in the Arduino which include:

•	Limit/stop the speed of the wheels

•	Making right and left turns

•	All changes on the wheels work in gradual spins which make it safer for the rider and not change drasticly which could be dangerous.

Here we can see it working real(not yet on the road) I'm using the RC that I build, the computer blocks the view for him.

https://www.youtube.com/watch?v=cZuwJM2zBeA&t=1s&ab_channel=%D7%90%D7%95%D7%A4%D7%99%D7%A8%D7%93%D7%94%D7%9F

After a long time that I didn’t touch the project, I changed the distance sensor to lidar cause it is accurate and long-range. Then I organized my code from the beginning cause it started to get messy. so I divided my code into different layers like in operation systems and now it is more organized

The next step is to add a gyro sensor to the systems for improving performance.

To bee continued…..

