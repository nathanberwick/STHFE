# STHFE
Simple Timer Hold Function Example - here in case I need it again!

important notes!
- timer.run(); needed at start of loop.
- timer.enable(timerID); and timer.disable(timerID); needed to turn off and on. disable does the resetting.
- timer.setInterval(); sets the timer but means it's more than just a one off. in this case, if it sets the flag several times after being repeated, that's fine if it's just a one off. could have int flag and increment and read for "what function did we hold for".
