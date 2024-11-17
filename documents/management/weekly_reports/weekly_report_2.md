# Weekly Report of Guillaume DESPAUX Moonshot
### Weekly Report - Week of November 11, 2024

1. **Introduction:**  
- This week I started to learn how to create Arduino projects to figure out what will be the components to build the hardware needed. The board will be **ESP32** (board with integrated Wi-Fi and Bluetooth with USB Type-C connector), NFC reader.
- I had to revise the execution order for the double authentication system:
    1. ~~QR Code~~ **NFC Card**
        - ~~Use the phone to scan one unique QR Code after presenting the user card, that redirects onto the Skills website.~~
        - The user will use an NFC card on the hardware to unlock the first step of double authentication.
    2. ~~Pin code~~ **Software Notification**
        - ~~Every student will have a unique code for each project to log in after the card.~~
        - The hardware will check the ID given by the user's card and send (if valid) a notification to the API that will respond back to the software.
    3. **User Validation**
        - **Computer application**
            - After the card presentation, a notification will pop up on the user's computer to ensure that it is really them.
        - **Phone application**
            - After the card presentation, a notification will pop up on the user's phone to ensure that it is really them.

2. **Accomplishments:**  
- Learned how to join wires for Arduino.

3. **Challenges:**  
- Peek the right components and be sure of the compatibility.

4. **Plans for Next Week:**  
- Continue the functional specification.
- Start the technical specification.

5. **Conclusion:**  
This week was productive as I made significant progress in understanding the components required for our hardware setup and revised the execution order for the double authentication system. I am confident that the changes made will enhance the security and usability of our project. Next week, I plan to continue working on the functional specification and begin the technical specification to ensure we stay on track with our project timeline.

[Back to the Management Artifact](../management_artifacts.md#weekly-reports)