# Traffic Light Project
 
 https://www.youtube.com/playlist?list=PLR1_kFCzdgsWP8nX3tXHa1se6xsXVpmP7
 
 ![trs](https://user-images.githubusercontent.com/56139834/211884201-79d27c11-7479-4bfb-ad7b-097797159f54.png)

## System description
 
Traffic lights are signaling devices positioned at road intersections or at pedestrian crossings to control flow of traffic .
It consists of three lights (red ,yellow ,green).
Crosswalk buttons are added so a pedestrian can cross the road .

## System design
### System components :
- Traffic light for the cars. (three LEDS :red , yellow, green)
- Traffic light for pedestrian .
- a push button.
- Timer.

### Sequence diagram

![seq](https://user-images.githubusercontent.com/56139834/211884775-72b3b6a8-fb11-4f43-9c05-bdcc27a24ab7.png)

## System flow chart
- at beginning the system enters normal mode and illuminates the car green led and the pedestrian red led for 5 seconds then turn pedestrian's red led and car's green led off and blink yellow LEDs for 5 seconds. Then turn pedestrian's green and car's red on.
- If the button is pressed traffic lights enter pedestrian mode.
If the pedestrian's green led is on do nothing and exit pedestrian mode ,if not blink the yellow LEDs for 5 seconds then turn pedestrian's green on and finally exits pedestrian mode

![flow chart](https://user-images.githubusercontent.com/56139834/211884788-b230205e-d355-4a32-972b-631e8664b2f3.png)

## Screenshots
- ### folder structure
 
  <img src="https://user-images.githubusercontent.com/56139834/211880648-d2415d78-bae5-4b00-962e-9c2b7b1e245e.PNG" width="300" height="500">
  
   ## Testing Functions
     
 <details>
           <summary>Timer Driver</summary><p>  

- `u8 Timer_Test(void)`

 <img src="https://user-images.githubusercontent.com/56139834/211881496-37d7cc43-42a0-4ba5-b073-1f275c18fadb.PNG" width="700" height="500">

 <img src="https://user-images.githubusercontent.com/56139834/211881468-9c374f05-97b0-4958-8c08-36fccbe4ce16.PNG" width="700" height="500">
 
 </p>
 </details>
 
  <details>
             <summary>DIO Driver</summary><p>  
             
- `u8 DIO_test(void)`

1-we initiate PortA pin0 as an output and pin1 as an input,PortB pin 0->2 as output.

2-set PortB pin0, clear Pin1,Toggle pin2.then read their values.

 <img src="https://user-images.githubusercontent.com/56139834/211882069-3d17965a-81ac-4556-97a4-98b525aed6f9.PNG" width="700" height="500">
 
 </p>
 </details>
 <details>
           <summary>LED Driver</summary><p>  
           
 - `void LED_test(void)`
 
 <img src="https://user-images.githubusercontent.com/56139834/211883319-2e6ea926-8e26-4e46-a78d-98941a5f56b1.PNG" width="700" height="500">
 
 </p>
 </details>
  <details>
           <summary>Button Driver</summary><p>  
           
 - `void Button_test(void)`
 
 <img src="https://user-images.githubusercontent.com/56139834/211883955-490f795e-924a-43d0-a2f7-7d02b5f7ee4a.PNG" width="700" height="500">
 
 </p>
 </details>
  
