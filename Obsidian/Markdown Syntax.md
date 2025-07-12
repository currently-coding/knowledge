---
title: Obsidian Markdown Feature Test
tags: [test, theme]
created: 2025-07-09
---
# H1 Heading

## H2 Heading

### H3 Heading

#### H4 Heading

##### H5 Heading

###### H6 Heading

---

## Paragraph & Emphasis

This is a **bold** word, this is *italic*, this is ~~strikethrough~~, and this is `inline code`.

---

## Lists

### Unordered list
- Item 1
  - Subitem 1
  - Subitem 2
    - Sub-subitem
- Item 2

### Ordered list
1. First
2. Second
3. Third
   4. Nested

### List Icons
 - [ ]  Unchecked       
 - [x]  Checked         
 - [>]  Rescheduled     
 - [<]  Scheduled       
 - [!]  Important       
 - [-]  Cancelled       
 - [/]  In Progress     
 - [?]  Question        
 - [*]  Star            
 - [n]  Note            
 - [l]  Location        
 - [i]  Information     
 - [I]  Idea            
 - [S]  Amount          
 - [p]  Pro             
 - [c]  Con             
 - [b]  Bookmark        
 - ["]  Quote           
 - [u]  Up              
 - [d]  Down            
 - [w]  Win             
 - [k]  Key             
 - [f]  Fire            

---

## Task List

- [ ] Incomplete task
- [x] Completed task
- [ ] Another one

---

## Quotes

> This is a blockquote.  
> It can span multiple lines.  
>> Nested quote.

---

## Code Blocks

```python
def hello(name):
    print(f"Hello, {name}!")
```

## Links

### Internal links
- [[To Be Created Note]]
- [[Existing Note]]
- [[Existing NoteExisting note with another name]]

### External links
- [Obsidian website](https://obsidian.md)

---

## Callouts

> [!note] This is a note callout
> You can write more text here.

> [!tip] This is a tip
> Useful for providing advice.

> [!warning] Warning
> Something might go wrong.

> [!info] Info
> Some informational text.

> [!example] Example
> Here’s an example of something.

>[!tip]+ Nested
>>[!Example]- Callouts
>>are cool!
>
>exist.
### Custom Callouts
>[!Task] This is a Task
> it has a nice icon

>[!Question]- This will be interpreted as a flashcard
> and this is the answer to it.

>[!Card]- This is a flashcard as well
>use >[!Question] or >[!Card]

---

## Tables

 Column 1  Column 2  Column 3 
------------------------------
 Row 1    Data 1    Data 2   
 Row 2    Data 3    Data 4   

---

## Math

Inline math: $E = mc^2$

Block math:
$$
\int_{a}^{b} f(x)dx
$$

---
## Footnotes

Here is a statement with a footnote[^1].

[^1]: This is the footnote text.
