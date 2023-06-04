# Creative Project 2
- Link to the live Draw Your Mind App deployed on Goldsmiths' virtual server:
https://www.doc.gold.ac.uk/www/676/~kzhan002/app/Draw_Your_Mind/index.html

- Link to Video Demonstration:
https://CP2-VIDEO.super.site/

Notion link to show all related information about the final implementation and its detailed interaction explanation: https://CP2-FINAL.super.site/

Rubric breakdown:
Part 1: Project Organization and time management specification via the link:
https://CP2-TIMELINE.super.site/
<img width="1042" alt="Screenshot 2023-06-04 at 14 30 25" src="https://github.com/KaiKz/year-2-project/assets/118116534/37cf9686-d8da-47a4-b576-4f604c6cdff3">

Part 2: Please find the Technical execution specification via the link:
https://CP2-CODE.super.site/
Part 3: Please find the submission: Creative Project Report.pdf - Links in the report: https://CP2-REPORT.super.site/
Owing to the size and resolution of the visual media, all such content in this report (including Pictures, Miro, Notion, etc.) has been transformed into links within footnotes, which direct to the appropriate media displays as needed.
Part 4: Please find the creative risk specifications via the link:
https://CP2-FUTURE-POTENTIAL.super.site/

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

Download documents mentioned in the Timeline:
[Angry Mode Challenge_ User Feedback Survey .pdf](https://github.com/KaiKz/year-2-project/files/11643474/Angry.Mode.Challenge_.User.Feedback.Survey.pdf)

[Draw Your Mind - User Feedback Survey.pdf](https://github.com/KaiKz/year-2-project/files/11643476/Draw.Your.Mind.-.User.Feedback.Survey.pdf)

[Emotion Detection_ Post-Test Interview.pdf](https://github.com/KaiKz/year-2-project/files/11643477/Emotion.Detection_.Post-Test.Interview.pdf)

[Emotion Detection_ Post-Test Survey.pdf](https://github.com/KaiKz/year-2-project/files/11643478/Emotion.Detection_.Post-Test.Survey.pdf)

[Emotion Detection_ Pre-Test Survey.pdf](https://github.com/KaiKz/year-2-project/files/11643479/Emotion.Detection_.Pre-Test.Survey.pdf)

[Happy Mode Challenge_ User Acceptance Testing Survey.pdf](https://github.com/KaiKz/year-2-project[Sad Mode Challenge_ User Feedback Survey .pdf](https://github.com/KaiKz/year-2-project/files/11643481/Sad.Mode.Challenge_.User.Feedback.Survey.pdf)
/files/11643480/Happy.Mode.Challenge_.User.Acceptance.Testing.Survey.pdf)

[Testing Emotion-based Modes_ survey questions.pdf](https://github.com/KaiKz/year-2-project/files/11643482/Testing.Emotion-based.Modes_.survey.questions.pdf)

[Summary of Survey and Interview Results.pdf](https://github.com/KaiKz/year-2-project/files/11643483/Summary.of.Survey.and.Interview.Results.pdf)

[Summary of User Survey and Interview Results.pdf](https://github.com/KaiKz/year-2-project/files/11643484/Summary.of.User.Survey.and.Interview.Results.pdf)

[UX Research_ User Interview Questions.pdf](https://github.com/KaiKz/year-2-project/files/11643485/UX.Research_.User.Interview.Questions.pdf)

[UX Research_ User Survey.pdf](https://github.com/KaiKz/year-2-project/files/11643486/UX.Research_.User.Survey.pdf)

[UX Testing_ Summary of the results.pdf](https://github.com/KaiKz/year-2-proj[UX Testing_ Survey .pdf](https://github.com/KaiKz/year-2-project/files/11643489/UX.Testing_.Survey.pdf)

ect/files/11643487/UX.Testing_.Summary.of.the.results.pdf)
[Uploading UX Testing_ Survey .pdf…]()
[Interview Results Summary.pdf](https://github.com/KaiKz/year-2-project/files/11643490/Interview.Results.Summary.pdf)

[Survey Results Summary.pdf](https://github.com/KaiKz/year-2-project/files/11643491/Survey.Results.Summary.pdf)

[Emotion detection_ Summary of Test Plan Results.pdf](https://github.com/KaiKz/year-2-project/files/11643493/Emotion.detection_.Summary.of.Test.Plan.Results.pdf)

[User Interview Script – Draw your mind.pdf](https://github.com/KaiKz/year-2-project/files/11643494/User.Interview.Script.Draw.your.mind.pdf)

[Emotion detection_ Test plan.pdf](https://github.com/KaiKz/year-2-project/files/11643495/Emotion.detection_.Test.plan.pdf)

[User Survey – Drew your mind.pdf](https://github.com/KaiKz/year-2-project/files/11643497/User.Survey.Drew.your.mind.pdf)




<img width="1042" alt="Screenshot 2023-06-04 at 14 30 25" src="https://github.com/KaiKz/year-2-project/assets/118116534/1f76eec9-7a0d-42a4-9033-f2854d8d6ed2">


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


# Stage 2: Improved Emotion Detection and User Interface
<img width="1171" alt="Screenshot 2023-05-18 at 12 01 44" src="https://github.com/KaiKz/year-2-project/assets/118116534/27201e3a-bd31-4820-a55b-5ef8e3bbbd74">

1. **Fine-tuning Emotion Detection Algorithms**: In this step, the algorithms used for calculating emotion scores were fine-tuned to improve the accuracy of the emotion detection feature. This involved adjusting the weights assigned to different visual elements (e.g., brush shapes, colors) based on their associations with different emotions.
2. **Incorporating Additional Research**: Additional research was conducted on the relationships between visual elements and emotions. The findings from this research were incorporated into the emotion detection algorithms to further improve their accuracy.
3. **Redesigning User Interface**: The user interface was redesigned to be more intuitive and visually appealing. This involved changes to the layout, colour scheme, and interactive elements of the interface.
4. **Test: Second Group of Users**: A second group of users was invited to test the improved prototype. They were asked to complete the same questionnaire as in the first stage and provide suggestions for any new features or improvements they would like to see in the program.
5. **Reflection: Results and Feedback**: The results from the second test were analyzed, and the feedback from users was taken into consideration. This showed significant improvements in the accuracy of the emotion detection feature and the usability of the user interface.
6. **Development of Creative Challenge Feature**: Based on the feedback from users, a creative challenge feature was developed for the third stage. This feature was designed to engage users in the drawing process and help them transition from negative emotions to a happier state.
7. **Anger Mode**: For users detected with anger, the program enters the Anger Mode. In this mode, users are encouraged to draw in a black-and-white mode using a brush with a basic shape. This is designed to reduce cognitive load and have a calming effect.
8. **Sad Mode**: For users detected with sadness, the program enters the Sad Mode. In this mode, users are encouraged to draw with a cycling colour mode using a brush with a non-basic shape. This is designed to stimulate creativity and provide a sense of joy and excitement.
9. **Happy Mode**: After completing the respective challenges for angry and sad users, they are transitioned into Happy Mode. In this mode, a hidden gift of special brushes that can create fancy paintings is revealed. This is designed to provide a sense of novelty and excitement and improve the user's mood.

# Stage 3: Implementation of the Creative Challenge

<img width="1169" alt="Screenshot 2023-05-18 at 12 09 59" src="https://github.com/KaiKz/year-2-project/assets/118116534/8fba8c83-83fa-4c4b-b57e-68b039df15ef">

1. **Start Menu**: This is the initial screen that users see when they open the program. They have four options: Start painting, Instructions, Exit, and My works.
2. **Painting Mode**: When users click "Start Painting", they enter the painting mode where they can interact with the program through mouse dragging and keyboard pressing. They can choose different brushes, colors, and sizes for their painting.
3. **Emotion Detection**: After users click "Continue", the program automatically detects the user's most likely emotion (anger, happiness, or sadness) based on their interactions and inputs during the painting process.
4. **Anger Mode**: If the detected emotion is anger, the program enters the anger mode. Users are encouraged to pick a brush with a basic shape and draw in a black-and-white mode. This challenge is designed to reduce cognitive load and help users focus on expressing their emotions.
5. **Sad Mode**: If the detected emotion is sadness, the program enters the sad mode. Users are encouraged to pick a brush with a non-basic shape and draw with a cycling color mode enabled. This challenge is designed to stimulate the user's creativity and provide a sense of joy and excitement.
6. **Happy Mode**: After completing the respective challenges for anger and sadness, users are transitioned into the happy mode. In this mode, a hidden gift of special brushes is revealed. This reward is designed to improve the user's mood and make them feel accomplished.
7. **End of Session**: After the user has completed the creative challenge and received their reward, the session ends.
8. **Instruction Mode**: At any point during the painting mode, users can click "Instruction" to view the instructions for the program. They can then return to the painting mode by clicking "Continue".

# Final implementation
<img width="733" alt="Screenshot 2023-05-18 at 12 25 20" src="https://github.com/KaiKz/year-2-project/assets/118116534/e08ffc68-67ae-494c-8846-10908ef574b5">
This diagram shows the different modes of my program and how the user transitions between them.

1. **START_MENU**: This is the initial state of the program where the user can choose to start painting, view instructions, exit the program, or view their works.
2. **PAINTING_MODE**: If the user chooses to start painting, they enter this mode. Here, they can interact with the program through mouse dragging and keyboard pressing. They can change the brush size, brush type, colour, enable animations, and more.
3. **Emotion Detection**: Once the user clicks "Continue", the program automatically detects the user's most likely emotion based on their interactions and inputs while painting. This is done by analyzing the shape, size, and colour of the brushes used.
4. **ANGER_MODE, SAD_MODE, HAPPY_MODE**: Depending on the detected emotion, the user is directed to one of these modes. Each mode incorporates a creative challenge designed specifically for the detected emotion. For example, users detected with anger are encouraged to draw in black and white mode, while users detected with sadness are encouraged to draw with a cycling colour mode. If the user is detected as happy, they are directed to the happy mode without any challenge.
5. After completing the respective challenges for angry and sad users, they are transitioned into **HAPPY_MODE**. In this mode, a hidden gift of special brushes that can create fancy paintings is revealed.

# Interaction and Functionality

1. **Start Menu**: Upon opening the program, the user is presented with a start menu that includes four options: Start Painting, Instructions, Exit, and My Works.
2. **Start Painting**: If the user selects "Start Painting", they enter the PAINTING_MODE. In this mode, the user can interact with the program through mouse dragging and keyboard pressing. The following options are available:
    - Dragging the mouse allows the user to paint on the canvas.
    - Pressing 'm' enables a black-and-white mode, designed for users experiencing anger.
    - Pressing 'w' enables the user to change the brush size, with 'e' for a larger size and 's' for a smaller size.
    - Pressing 'b' allows the user to change brushes, with numbers 0-9 corresponding to different brushes.
    - Pressing 'c' enables colour change, with 'r', 'g', 'b' increasing red, green, and blue respectively, and 'R', 'G', 'B' decreasing them.
    - Pressing 'h' enables a cycle colour mode, designed for users experiencing sadness.
    - Pressing 'a' enables animations, with numbers 1-5 corresponding to different animations.
    - Pressing 'x' takes a screenshot of the current canvas, which can be found in the bin.
    - Pressing 'z' undoes the last action, and 'y' redoes the last undone action.
3. **Emotion Detection**: After the user has finished painting and clicks "Continue", the program's emotion detection feature is triggered. This feature analyzes the user's painting based on the shapes, sizes, and colours of the brushes used, and classifies the user's emotion as either happy, sad, or angry.
4. **Emotion-Specific Modes**: Depending on the detected emotion, the program enters one of three modes: ANGER_MODE, SAD_MODE, or HAPPY_MODE. Each mode presents a creative challenge tailored to the user's emotion:
    - **Anger Mode**: Users are encouraged to draw using a basic shape brush in black-and-white mode. This is designed to help users focus on expressing their emotions without the distraction of multiple colours.
    - **Sad Mode**: Users are encouraged to draw using a non-basic shape brush with a cycling colour mode. This is designed to stimulate the user's creativity and provide a sense of joy and excitement.
    - **Happy Mode**: Users are rewarded with a hidden gift of special brushes that can create fancy paintings. This is designed to provide a sense of novelty and excitement, further contributing to the user's happiness.
5. **Art Therapy**: The program uses the principles of art therapy to help users express and cope with their emotions. By channelling their emotions into artistic expression, users can experience a therapeutic effect and improve their emotional well-being.
6. **Cognitive Load**: The program is designed to reduce cognitive load for users experiencing anger by simplifying the choice of shapes and colours. This can help users concentrate on the task at hand and find relief from their emotional state.
7. **Colour Psychology**: The program uses the principles of colour psychology to stimulate the senses and evoke positive emotions in users experiencing sadness. The continuous change of colours can symbolize change and growth, which can be helpful for users experiencing sadness.
8. **Positive Reinforcement**: The program uses the technique of positive reinforcement by providing a hidden gift of special brushes as a reward for completing the challenge. This can boost the user's self-esteem and provide positive reinforcement, which is known to be an effective technique for behaviour change and mood improvement.

# Emotion Detection Algorithm

The emotion detection feature is triggered when the user clicks the "Continue" button after painting. The program then analyses the user's painting based on the three aspects mentioned above. The relevant code snippet for this feature is as follows:

Emotion ofApp::classifyEmotion() {
    // Emotion scores based on brush proportions
    std::unordered_map<Emotion, float> emotionScores = {
        {HAPPY, 0},
        {SAD, 0},
        {ANGRY, 0}
    };
    
    // Brush emotion weights
    std::unordered_map<meshBrushTypes, std::unordered_map<Emotion, float>> brushEmotionWeights = initializeBrushEmotionWeights();
    
    // Calculate the emotion score based on the brush proportions
    for (const auto& brushCounter : brushCounters) {
        for (const auto& emotionScore : emotionScores) {
            Emotion emotion = emotionScore.first;
            emotionScores[emotion] += brushCounter.second * brushEmotionWeights[brushCounter.first][emotion];
        }
    }
    
    // Calculate emotion scores based on color and size proportions
    for (const auto& colorCounter : colorCounters) {
        float saturation = colorCounter.first.getSaturation();
        float brightness = colorCounter.first.getBrightness();
        float size = colorCounter.second;
        // Factor in saturation and brightness for happy emotion
        emotionScores[HAPPY] += (saturation * brightness * size * 0.1);
        
        // Factor in low saturation and brightness for sad emotion
        emotionScores[SAD] += ((1 - saturation) * (1 - brightness) * size * 0.1);
        
        // Factor in saturation and low brightness for angry emotion
        emotionScores[ANGRY] += (saturation * (1 - brightness) * size * 0.1);
    }
    
    // Find the emotion with the highest score
    Emotion detectedEmotion = HAPPY;
    float maxScore = 0;
    for (const auto& emotionScore : emotionScores) {
        if (emotionScore.second > maxScore) {
            maxScore = emotionScore.second;
            detectedEmotion = emotionScore.first;
        }
    }
    
    return detectedEmotion;
}

1. **Enum Declarations**: The code begins by declaring two enums: **`meshBrushTypes`** and **`Emotion`**. Enums (short for enumerations) are a type that consists of a set of named values. In this case, **`meshBrushTypes`** represents the different types of brushes that can be used, and **`Emotion`** represents the three possible emotions that can be detected (HAPPY, SAD, ANGRY).
2. **classifyEmotion Function**: This function is responsible for classifying the user's emotion based on their interactions with the program. It does this by calculating an "emotion score" for each possible emotion, based on the types of brushes used, the colors used, and the sizes of the brushes. The emotion with the highest score is then returned as the detected emotion.
3. **initializeBrushEmotionWeights Function**: This function initializes a map that associates each type of brush with a set of weights for each possible emotion. These weights are used in the **`classifyEmotion`** function to calculate the emotion scores.
4. **printVisualElementsProportions Function**: This function prints out the proportions of different visual elements used by the user. This includes the proportions of different types of brushes, colours, and sizes.
5. **launchAngryInterfaceFlowMode, launchSadInterfaceFlowMode, launchHappyInterfaceFlowMode Functions**: These functions are responsible for transitioning the program into different modes based on the detected emotion. Each mode presents a different creative challenge to the user, designed to help them express and cope with their emotion.
6. **Emotion Detection Algorithm**: The emotion detection algorithm works by first calculating the proportions of different visual elements used by the user (types of brushes, colors, sizes). Then, it calculates an emotion score for each possible emotion based on these proportions and the weights associated with each visual element. The emotion with the highest score is then detected as the user's emotion.

# Emotion-Specific Modes

Once the user's emotion is detected, the program enters a mode corresponding to the detected emotion: ANGER_MODE, SAD_MODE, or HAPPY_MODE. Each mode presents a creative challenge designed specifically for users experiencing that emotion.

In ANGER_MODE, users are encouraged to draw in black and white using basic shapes. This challenge is designed to help users focus on expressing their emotions without the distraction of multiple colors.

In SAD_MODE, users are encouraged to draw with a cycling color mode enabled, using non-basic shapes. This challenge is designed to stimulate the user's creativity and provide a sense of joy and excitement.

In HAPPY_MODE, users are presented with a hidden gift of special brushes that can create fancy paintings. This reward is designed to boost the user's mood and provide a sense of accomplishment.

The relevant code snippets for these modes are as follows:

Void ofApp::launchAngryInterfaceFlowMode() {
previousUserFlowMode = userFlowMode;
userFlowMode = ANGER_MODE;
angerModeCounter = 0;
canvasFbo.begin();
ofClear(0); // Set the background to black
canvasFbo.end();
completedAngerMode = false;
}

void ofApp::launchSadInterfaceFlowMode() {
previousUserFlowMode = userFlowMode;
userFlowMode = SAD_MODE;
sadModeCounter = 0;
canvasFbo.begin();
ofClear(0); // Set the background to black
canvasFbo.end();
completedSadMode = false;
}

void ofApp::launchHappyInterfaceFlowMode(){
previousUserFlowMode = userFlowMode;
userFlowMode = HAPPY_MODE;
canvasFbo.begin();
ofClear(0); // Set the background to black
canvasFbo.end();
db2IsOn==true;
}

<img width="1157" alt="Screenshot 2023-05-18 at 16 48 51" src="https://github.com/KaiKz/year-2-project/assets/118116534/f954c8da-0927-4890-81a6-828c2de4ed20">

This diagram represents the process of emotion detection in my application. It starts with the Emotion Detection node, which branches out into three main components: Brush Proportions, Color Proportions, and Size Proportions.

- **Brush Proportions**: This component calculates the emotion score based on the proportions of different brushes used by the user.

std::unordered_map<Emotion, float>> initializeBrushEmotionWeights() {
    std::unordered_map<meshBrushTypes, std::unordered_map<Emotion, float>> brushEmotionWeights;
    
    brushEmotionWeights[MESH_BRUSH_DOT] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_TRIANGLE] = { {HAPPY, 0.05}, {SAD, 0.1}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_SQUARE] = { {HAPPY, 0.05}, {SAD, 0.05}, {ANGRY, 0.1} };
    brushEmotionWeights[MESH_BRUSH_CIRCLE] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_HEXAGON] = { {HAPPY, 0.05}, {SAD, 0.1}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_HEART] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_STAR] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_WAVYCIRCLE] = { {HAPPY, 0.05}, {SAD, 0.1}, {ANGRY, 0.05} };
    brushEmotionWeights[MESH_BRUSH_SPIRAL] = { {HAPPY, 0.05}, {SAD, 0.05}, {ANGRY, 0.1} };
    brushEmotionWeights[MESH_BRUSH_SUN] = { {HAPPY, 0.1}, {SAD, 0.05}, {ANGRY, 0.05} };
    
    return brushEmotionWeights;
}

The function **`initializeBrushEmotionWeights()`** is a crucial part of the emotion detection feature in my program. It initialises a data structure that maps different types of brushes to different emotions (HAPPY, SAD, ANGRY) and assigns a weight to each brush-emotion pair. These weights are used later in the **`classifyEmotion()`** function to calculate the emotion scores.

Here's a breakdown of what the function does:

1. It first declares an unordered map **`brushEmotionWeights`** that uses **`meshBrushTypes`** as keys and another unordered map as values. The inner unordered map uses **`Emotion`** as keys and **`float`** as values. This creates a two-level map structure where a brush type is associated with a set of emotions, and each emotion is associated with a weight.
2. For each brush type, it assigns a weight to each emotion. These weights are used to calculate the emotion scores in the **`classifyEmotion()`** function. The weights are set based on the assumption that different brush types are more likely to be used by users experiencing different emotions. For example, the DOT brush is associated with a higher weight for the HAPPY emotion (0.1) than for the SAD or ANGRY emotions (0.05 each).
3. Finally, it returns the **`brushEmotionWeights`** map.

- **Colour Proportions**: This component calculates the emotion scores based on the proportions of different colours used by the user.
- **Size Proportions**: This component calculates the emotion scores based on the proportions of different sizes of brushes used by the user.

These three components contribute to the overall Emotion Scores, which are then used to find the emotion with the highest score, resulting in the Detected Emotion.
<img width="470" alt="Screenshot 2023-05-18 at 16 55 12" src="https://github.com/KaiKz/year-2-project/assets/118116534/e8c814b6-abaf-4b21-92a4-c47164745e2a">

This diagram illustrates the process from when the user starts painting to the detection of the user's emotion and the subsequent triggering of the corresponding mode.

1. The user starts painting and makes various interactions with the application, such as selecting brushes, colors, and sizes.
2. These user choices are recorded and counted.
3. The proportions of the different brushes, colours, and sizes used by the user are calculated.
4. Based on these proportions, the user's emotion is classified as either anger, sadness, or happiness.
5. Depending on the detected emotion, the corresponding mode (Anger Mode, Sad Mode, or Happy Mode) is triggered.
6. If the user is detected as angry or sad, they must complete a challenge to transition into Happy Mode.
7. Once in Happy Mode, special brushes are revealed for the user to continue painting.

# Creative Risk Specifications

**Creative Risk Specifications:**

1. **Emotion Detection Algorithm**: The program's innovative approach to emotion detection through user interaction is a significant creative risk. The algorithm's effectiveness relies on the assumption that the choice of brushes, colours, and sizes directly correlates with the user's emotional state. If this assumption doesn't hold for all users, the emotion detection might not be accurate, leading to a mismatch between the user's emotional state and the mode triggered by the program.
2. **User Interface Design**: The program's user interface design is another area of creative risk. The design must be intuitive and engaging to ensure users can easily navigate through the different modes and understand the instructions. If the design is too complex or not user-friendly, it could deter users from fully engaging with the program.
3. **Emotion-Specific Challenges**: The program presents users with creative challenges based on their detected emotion. This is a unique feature that adds an element of gamification to the program. However, it also carries the risk of oversimplification. Emotions are complex and can't always be effectively addressed through a single challenge. Users might find the challenges too simplistic or not helpful in managing their emotions.
4. **Privacy and Data Handling**: The program collects and analyzes user interaction data for emotion detection. While this is necessary for the program to function, it also raises privacy concerns. Users might be hesitant to use the program if they are not comfortable with their data being collected and analyzed, even if it is for the purpose of improving their user experience.

**Future Potential:**

1. **Therapeutic Applications**: The program could be used as a digital therapeutic tool to help individuals manage their emotions. It could be particularly useful for individuals dealing with mental health issues such as depression or anxiety. The program could be further developed to include more modes and challenges tailored to specific emotional states.
2. **Personalized User Experience**: The program could incorporate machine learning algorithms to learn from user interactions and provide a more personalized user experience. For instance, it could recommend specific brushes or colours based on the user's past interactions. This could make the program more engaging and effective in helping users express their emotions.
3. **Integration with Other Platforms**: The program could be integrated with other platforms or applications to provide a comprehensive digital wellness solution. For instance, it could be integrated with meditation apps to provide a holistic approach to emotional well-being.
4. **Expansion to Other Art Forms**: The program currently focuses on painting. However, it could be expanded to include other forms of art such as music or poetry. This could attract a wider user base and provide more ways for users to express their emotions.
5. **Research Tool**: The program could be used as a research tool to study the relationship between art and emotions. It could provide valuable insights into how different aspects of art (such as colour or shape) influence emotions.
6. **Educational Tool**: The program could be used as an educational tool to teach children about emotions. It could help children understand their emotions and learn healthy ways to express them.
7. **Commercial Applications**: The program could be commercialized and marketed as a digital art tool with unique emotion detection features. It could appeal to both amateur and professional artists who are interested in exploring the intersection of art and emotions.
8. **Collaborative Art Creation**: In the future, the program could be developed to allow multiple users to collaborate on a single artwork. This could provide a new way for users to connect with each other and express their emotions collectively.

Thanks
