# Creative Project 2
- Link to the Draw Your Mind App(final result):
https://www.doc.gold.ac.uk/www/676/~kzhan002/app/Draw_Your_Mind/index.html

- Link to Video Demonstration:
https://CP2_VIDEO.super.site/

-Notion link to show all related information about the final implementation and its detailed interaction explanation: https://CP2_FINAL.super.site/

Rubric breakdown:
Part 1: Project Organization and time management specification via the link:
https://CP2_TIMELINE.super.site/
Part 2: Please find the Technical execution specification via the link:
https://CP2_CODE.super.site/
Part 3: Please find the submission: Creative Project Report.pdf - Links in the report: https://CP2_REPORT.super.site/
Owing to the size and resolution of the visual media, all such content in this report (including Pictures, Miro, Notion, etc.) has been transformed into links within footnotes, which direct to the appropriate media displays as needed.
Part 4: Please find the creative risk specifications via the link:
https://CP2_FUTURE_POTENTIAL.super.site/

# Video Demonstration:
Sad Mode: https://youtu.be/STBx4rQCr58
Happy Mode: https://youtu.be/uTIdzFqQ4jI
Angry Mode: https://youtu.be/C5FJcBPF3H8

Here's a detailed explanation of how the emotion detection works in the “Draw Your Mind” painting program:

1. **Brush Proportions**: The program first calculates the proportions of different brush types used by the user. Each brush type is associated with a certain weight for each emotion (Happy, Sad, Angry). For example, the Dot brush has a weight of 0.1 for Happy, 0.05 for Sad, and 0.05 for Angry. The Triangle brush has a weight of 0.05 for Happy, 0.1 for Sad, and 0.05 for Angry, and so on. These weights are used to calculate an initial emotion score based on the brush types used.
2. **Colour and Size Proportions**: The program also takes into account the colour and size proportions used in the painting. The saturation and brightness of the colors used, as well as the size of the brush strokes, are factored into the emotion scores. For example, high saturation and brightness contribute to the Happy score, low saturation and brightness contribute to the Sad score, and high saturation with low brightness contributes to the Angry score.
3. **Emotion Classification**: After calculating the emotion scores based on brush, colour, and size proportions, the program classifies the emotion by selecting the one with the highest score.

Here's a more detailed breakdown for each emotion:

- **Happy**: The Happy score increases with the use of Dot, Circle, Heart, Star, and Sun brushes. It also increases with the use of colours that have high saturation and brightness.
- **Sad**: The Sad score increases with the use of Triangle, Hexagon, and WavyCircle brushes. It also increases with the use of colours that have low saturation and brightness.
- **Angry**: The Angry score increases with the use of Square and Spiral brushes. It also increases with the use of colours that have high saturation but low brightness.

# Timeline(Miro Board):
https://miro.com/app/board/uXjVMIO74tE=/?share_link_id=270579620140

# MVP Strategy illustration
<img width="478" alt="Screenshot 2023-05-18 at 09 47 03" src="https://github.com/KaiKz/year-2-project/assets/118116534/bd08e5e3-1fca-4378-a4b8-c6b1d6ba5eeb">

1. "Idea": This is the initial stage where I came up with the idea for a painting program that can detect and respond to the user's emotions.
2. "Problem Recognition": I identified a problem that people might have difficulty expressing their emotions, and I thought of a solution where a painting program could help them express and cope with their emotions.
3. "Solution Development": I developed a solution in the form of a painting program with emotion detection features.
4. "Minimal Features": I decided on a minimal set of features for the MVP, which included painting tools, emotion detection, and different modes based on the detected emotion.
5. "Build MVP": I built the MVP of my program with the minimal set of features.
6. "Launch and Feedback": I launched the MVP and gatahered feedback from users.
7. "Iteration": Based on the feedback, I made improvements to the program and added new features, such as the creative challenges for angry and sad users and the hidden gift for happy users. This process of iteration continues as I gather more feedback and make further improvements to the program.

# Experiment A: Personalised Conversation

Miro:
https://miro.com/app/board/uXjVP7HC2hk=/?share_link_id=304439511243
<img width="546" alt="Screenshot 2023-05-18 at 09 59 21" src="https://github.com/KaiKz/year-2-project/assets/118116534/2774b69a-6334-4413-8419-d235ef557769">

In this diagram:

- "Start": This is the initial stage where the user begins interacting with the chatbot.
- "User Interaction": The user interacts with the chatbot by providing text input.
- "Emotion Detection": The chatbot detects the user's emotional state based on their text input.
- "Response Generation": The chatbot generates a response tailored to the user's detected emotional state.
- "User Response": The user receives and reacts to the chatbot's response.
- "User Feedback": The user provides feedback on the chatbot's performance.
- "Iteration": Based on the user's feedback, improvements are made to the chatbot, and the process repeats from the "User Interaction" stage.

# Experiment B: Art Therapy Suggestions
<img width="657" alt="Screenshot 2023-05-18 at 11 19 46" src="https://github.com/KaiKz/year-2-project/assets/118116534/81d2e468-ead0-4517-8ab4-2ce1686aeb5b">

In this diagram:

- "Start": This is the initial stage where the user begins interacting with the chatbot.
- "User Interaction": The user interacts with the chatbot, providing input that the chatbot can use to detect the user's emotional state.
- "Emotion Detection": The chatbot detects the user's emotional state based on their input.
- "Art Therapy Suggestions": Based on the detected emotion, the chatbot suggests specific art therapy exercises or creative prompts for the user.
- "User Response": The user responds to the suggestions, providing feedback that the chatbot can learn from.
- "Learning and Improvement": The chatbot learns from the user's responses and improves its ability to provide relevant and effective art therapy suggestions. This learning and improvement process is iterative, with the chatbot continually improving as it interacts with more users.

# Experiment C: Resource Recommendations
<img width="528" alt="Screenshot 2023-05-18 at 11 26 50" src="https://github.com/KaiKz/year-2-project/assets/118116534/6ee91a5b-3b2b-4166-8b0b-de45e772689c">

In this diagram:

- "Start": This is the initial stage where the user begins interacting with the chatbot.
- "User Interaction": The user interacts with the chatbot, providing input that the chatbot can analyze.
- "Emotion Detection": The chatbot uses natural language processing and a neural network to detect the user's emotional state based on their text input.
- "Resource Recommendations": Based on the detected emotion, the chatbot provides recommendations for resources that could help the user learn more about their emotions and how to manage them.
- "User Engagement": The user engages with the recommended resources, providing an opportunity for them to explore and learn about their emotions.
- "Feedback Collection": Feedback is collected from the user about the relevance and effectiveness of the resource recommendations.
- "Improvements Identification": Based on the feedback, improvements to the chatbot and the resource recommendations are identified.
- "Iteration and Improvement": The chatbot is iteratively improved based on the identified improvements, and the process repeats with the user interacting with the improved chatbot.

# Stage 1: Initial Prototype
<img width="575" alt="Screenshot 2023-05-18 at 11 36 38" src="https://github.com/KaiKz/year-2-project/assets/118116534/f384f0a1-c0d4-4203-ba9f-2dfd13058a56">

1. **Develop Basic Prototype**: In this step, I developed a basic prototype of my program. This included the emotion detection feature and a simple user interface for drawing.
2. **Test with Small User Group**: Once the basic prototype was ready, you tested it with a small group of users. This allowed me to gather initial feedback and understand how users interacted with my program.
3. **User Feedback**: The users provided feedback on the overall concept of my program, the usability of the interface, and the effectiveness of the emotion detection feature.
4. **Reflection on Feedback**: After receiving feedback, I reflected on the comments and suggestions made by the users. This helped me identify areas of improvement for my program.
5. **Identify Improvements**: Based on the feedback and my reflections, I identified improvements that could be made to enhance the emotion detection feature and the user interface. These improvements were then implemented in the next stage of development.

Survey Downloading here:[Dwonload Stage 1 User Survey.pdf](https://github.com/KaiKz/year-2-project/files/11643468/Dwonload.Stage.1.User.Survey.pdf)

Survey Results:
1. **Overall Experience**: The average rating was 8.5, indicating a positive user experience.
2. **Usability**: Users found the program easy to navigate, with an average rating of 8.7. Some users mentioned difficulties with understanding the different brush types and their associated emotions.
3. **Emotion Detection Feature**: The accuracy rating was 7.9. Users appreciated the feature but some found it not always accurate in detecting their emotions.
4. **Artwork Creation**: Users enjoyed the process of creating artwork, with an average rating of 9.2. Some users requested more brush options and colors.
5. **Creative Challenges**: Users found the challenges helpful in expressing their emotions, with an average rating of 8.8. Some users suggested including more challenges for a wider range of emotions.
6. **Improvements**: Users suggested adding more brush types, improving the accuracy of the emotion detection feature, and including more creative challenges.
7. **Final Thoughts**: Users appreciated the therapeutic aspect of the program and the positive impact it had on their mood.

<img width="852" alt="Screenshot 2023-05-18 at 11 54 36" src="https://github.com/KaiKz/year-2-project/assets/118116534/d5c0576a-4bac-4a92-82e0-a41460414b7a">

Reflection and Summary:

The survey results indicate that users generally had a positive experience with the program. They found it easy to navigate and enjoyed the process of creating artwork. The emotion detection feature was well-received, although some users felt it could be more accurate. The creative challenges were found to be helpful in expressing emotions, and users appreciated the therapeutic aspect of the program.

Based on the feedback, several improvements could be made to enhance the user experience. These include adding more brush types and colours, improving the accuracy of the emotion detection feature, and including more creative challenges. These improvements could make the program more engaging and therapeutic for users, and could potentially increase the accuracy of the emotion detection feature.

The survey results also highlight the importance of user feedback in the development process. By gathering and analyzing user feedback, you can identify areas of the program that are working well and areas that could be improved. This can help you make informed decisions about future updates and improvements, ultimately leading to a better product and a better user experience.

The program's ability to detect user emotions and adjust the interface and challenges accordingly is a unique and innovative feature that sets it apart from other art programs. This feature, combined with the therapeutic aspect of the program, makes it a valuable tool for users looking to express their emotions through art.

Overall, the program has been successful in achieving its goal of helping users express their emotions through art. With some improvements and updates based on user feedback, it has the potential to become an even more effective and enjoyable tool for emotional expression and therapy.
