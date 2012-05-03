*****************************************************************
Texas Hold'em

Created by:
Matt Brittan		mbrittan@nd.edu
Kevin Jacobs		kjacobs3@nd.edu
Scott Aufderheide	saufderh@nd.edu

Final Project
Fundamentals of Computing II, Spring 2012
Professor Scott Emrich
****************************************************************


---------READ ALL OF THIS FILE BEFORE RUNNING THE GAME----------

OVERVIEW: 

Texas Hold'em is a variation of poker.

- The game starts with the placing of the blinds. Large blind and
	small blind placement alternate with each hand. 

- The user and the computer are dealt two cards each and proceed
	with the first round of betting.

- After the first round of betting, the flop (first three community
	cards) are placed and there is another round of betting.

- After second round of betting, the turn (fourth community card)
	is placed and there is another round of betting.

- After third round of betting, the river (fifth community card)
	is placed and there is the final round of betting.

- If neither the player or the computer has folded, the computer's
	cards are revealed, and a winner is determined.

- The player can use the buttons on the left side of the interface 
	during each round of betting to check, call, bet, raise,
	or fold.
	
	-A bet makes an initial bet when the computer checks. An amount 
	must be entered in the adjacent text box before a bet is made.

	-A check means the player is still interested in playing,
	but not in betting. The player can only check if a bet has
	not been made yet. 
	
	-A call matches the current bet.

	-A raise increases the current bet. An amount must be entered in 	the adjacent text box before a bet is made.

	-Folding concedes the hand and all the money in the pot to 
	the computer. 

- Hands in increasing order: high card, pair, two pair, three of a
	kind, straight, flush, full house, four of a kind, straight
	flush.

	-High card is the player with the highest card.

	-A straight is five cards in increasing order.
	
	-A flush is five cards of the same suit. 
	
	-A full house is two cards of one value and three of another.

	-A straight flush is five cards of the same suit in increasing 
	order.

-If the player and the computer have the same type of hand, the one with
	the higher card value wins.

-In the case that hands are identical (tie), the pot is distributed evenly.

-All suits are of equal value in Texas Hold'em.


KNOWN ISSUES:

	Do NOT enter anything besides numbers in the editable text boxes.

	Segmentation fault if the user exits the window while the program
	is waiting for an event. As it is part of exiting the Qt Window, we 
	believe this is a problem with Qt.


REQUIREMENTS:

	Red Hat Enterprise Linux Server
		Release 6.2 (Santiago)
		Kernel Linux 2.6.32-220.7.1.eI6.x86_64
		GNOME 2.28.2

	Qt 4.4

	(lab computer)


INSTALLATION/IMPLEMENTATION:

	-Take the project folder and place where ever you desire.

	-Open a terminal window, navigate to the folder and type: 
	setenv QTDIR /usr/lib64/qt-3.3
	qmake-qt4 -project
	qmake-qt4
	make

	-Enter ./project, hit "Enter" and enjoy
