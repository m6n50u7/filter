# filter
a complex keyword detecting/filtering engine written in C language.<br/>
to configure the filter, you need to edit the three config files and place them in working directory.<br/>
the .slures.txt file containes the banned words seperated by semicolone.
the .negs.txt has the neglected strings/chars seperated by semicolone. any entry you put here will be ignored by the engine.<br/>
the .replacements.txt has the list of strings that are treated the same. the different enteries are seperated by semicolone and the equal sign seperates the subentries.<br />
the slurebot.py and .arnings.txt are a simple example of a telegram bot that warns users for the bad words and then deletes the messages.
