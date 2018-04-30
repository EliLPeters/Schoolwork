# Week 15 lab
# Eli Peters and Nathan Rothberg

import tkinter

class blow_it_up():
    def __init__(self, parent_window):
        self.string_var = tkinter.StringVar()
        self.frame = tkinter.Frame(parent_window)
        self.frame.grid()
        self.my_buttons()
        self.my_entry_box()
        self.my_labels()

    def my_buttons(self):
        self.blow_up_button = tkinter.Button(self.frame, font = ("Helvetica", 20))
        self.blow_up_button['text'] = "Blow it up"
        self.blow_up_button.grid(row = 0, column = 2)
        self.blow_up_button['command'] = self.blow_up
        
        self.done_button = tkinter.Button(self.frame, font = ("Helvetica", 20))
        self.done_button['text'] = "I\'m done"
        self.done_button.grid(row = 0, column = 3)
        self.done_button['command'] = self.frame.quit

    def quit(self):
        self.root.destroy

    def my_labels(self):
        self.enter_label = tkinter.Label(self.frame, font = ("Helvetica", 20))
        self.enter_label['text'] = "Enter word to blow up: "
        self.enter_label.grid(row = 0, column = 0)

        self.blown_up_label = tkinter.Label(self.frame, fg = 'red', font = ("Helvetica", 50))
        self.blown_up_label['text'] = " "
        self.blown_up_label.grid(row = 1, column = 0)

    def my_entry_box(self):
        self.input_box = tkinter.Entry(self.frame, font = ("Helvetica", 20))
        self.input_box['width'] = 10
        self.input_box.grid(row=0, column = 1)

    def blow_up(self):
        self.string_var.set(str(self.input_box.get()))
        self.blown_up_label['text'] = self.string_var.get()

def try_it():
    main_window = tkinter.Tk()
    main_window.title("Blow It Up Lab")
    main_window.geometry("800x200")

    x = blow_it_up(main_window)

    main_window.mainloop()

    try:
        main_window.destroy()
    except:
        print("USE THE BUTTON.")
        
