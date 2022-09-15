<center><h1> Project Title: C++ Keylogger, Ethical Hacking</h1></center>

<h2>Description:</h2>
<p>The program aims to work as a basic keylogger that will log all keyboard and mouse inputs into string that will then be transfer into a Powershell command, written into the C++ code, that will send the email, with attached key strokes, to the designated email address. 

What I've learned is the use of powershell in C++. Mailing through Powershell was a better option then one previously used in my Hospital Project. The powershell was showcased in the Youtube Tutorial. Previously I used Email Architects mailing service in the Windows.h and EASendMailObj.tlh. Really simple add-on that allows you to send emails. </p>

<h2>Challanges:</h2> 
<p>Though I followed the tutorial, I faced loads of issues with the CHAR* variables on getting the keystrokes to be saved. I did, however, think the simple solution was to just use #Include <STRING> and save it to a string. Made the string manipulation much easier as it was just adding the new letters to the string with a simple: 

<i>string = string + keystroke</i>

<i>Notes: </i> If you are going to use the Google Account setup currently in place, you will need to go into your Google Security Settings to get the App Permission Password.</p>

<h2>Credits:</h2> 

<h3>Youtube Tutorial: </h3> How to Build a KeyLogger in C++ | Learn C++ | C++ for Beginners
<h3>Link:</h3> <a href="https://www.youtube.com/watch?v=qWhtZqpNJhY&t=12248s">Youtube</a>
<h3>Tutorial Description:</h3> This C++ for Beginners series is about creating a Keylogger in C++. A KeyLogger is a program that can capture every key or click that is pressed on the computer asynchronously. In order to get useful information, we will learn how to erase the cache, build the keylogger and send the information via email. This tutorial will help you learn how to create a functional real-life KeyLogger from scratch in C++. Learn C++ from start. 
<h3>Youtube Channel:</h3> <a href="https://educationecosystem.com/">Education Ecosystem</a>
