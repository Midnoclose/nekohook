# Contributing to nekohook

## Note:
This is old, needs updating.

## About
Nekohook was made to replace and improve on cathook and the flaws I've seen with it.   
Avoid doing useless computations... If you can keep everything on stack, doesnt mean u cant use std::string for heap storage, just means avoid "new" or malloc unless absolutly needed...   

With the way nekohook was constructed, it is meant to work for multiple games.
This means avoid including anything from your modules into nekohook. This will add a dependancy of your module to nekohook which isnt wanted...
Use nekohooks own "modular" functions like the ones in src/framework/entities.hpp, src/framework/input.hpp, etc...   
These are ment to "pass through" your modules functions to nekohook, use them.

## Code
### Style
Loosely follow the [google style guide](https://google.github.io/styleguide/cppguide.html) unless the below guidelines overrule.

Use brackets on same line rather than new line.   
Omit brackets entirely if one liner actions
```cpp
// Good
if (true) {
    // Stuff
}
if (1 == 0)
    Stuff();

// Bad
if (false)
{
    // Stuff
}
```

Use 4 space indentation please!

### Naming
AVOID HUNGARIAN NOTATION AT ALL COSTS!!!   
You should have a proper ide, use its features!   
(Exception is kConstNames)   

Name functions with capital and CamelCase. This includes std::function and derivatives.   
Any and every variable should be named with lower_case_and_underlines. This includes globals and statics.

Use the google style guides kConstName format for enums and constants

## Commiting changes
### Setup branch
Clone the repo   
`git clone https://github.com/oneechanhax/nekohook`   
Make a new branch for your changes   
`git checkout -b <name goes here>`   

### Commit changes
Stage file for a commit   
`git add <file changed>`   
Ensure only wanted files are being commited   
`git status`   
Commit the changes   
`git commit -m "<This is the commit name>"`

If you made multiple commits for one issue or feature, [place all commits you have made locally into one commit](https://github.com/todotxt/todo.txt-android/wiki/Squash-All-Commits-Related-to-a-Single-Issue-into-a-Single-Commit)!

Finally push to github   
`git push`
