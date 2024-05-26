#!/bin/env python3
from telethon.sync import TelegramClient
from telethon import events
from telethon.tl.custom import Button
import time
import os

reps = open(".warnings", "r").read().split("\n")
i = 0
ln = len(reps)
bot = TelegramClient('token', 'api id', "api hash").start()
@bot.on(events.NewMessage)
async def send(event):
    if os.system("filter \'" + event.text.replace("'", "''") + "\'"):
        global i, ln, reps
        await event.reply(reps[i])
        i = (i + 1) % ln
        time.sleep(5)
        await event.delete()
def main():
	bot.run_until_disconnected()

if __name__ == '__main__':
    main()
