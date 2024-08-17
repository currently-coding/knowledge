---
tags:
  - "#rust"
links:
---
## State Pattern
- assigns a set of states to value
- the value can be 1 of those states
- states are represented by *state objects*
- each *state object rules itself*
	-> responsible for its *behaviour*
<!--SR:!2024-08-21,4,270-->
	-> responsible for when to *change to another state*
- the value holding a state object knows **nothing** about the state objects

- **Great Maintainability** -> No need to extend `match` statements, etc.


## Code Beispiele/Aufgaben
### Blog Post
- States: *"draft", "review", "publish*
- Structs: `Post`, `Draft`, `PendingReview`, `Published`
- Traits: `State`
- Functions: `Post.new()`, `Post.add_text(&mut self, text: &str`, `Post.content(&self)`

Filename: src/main.rs
```Rust
use blog::Post;

fn main() {
    let mut post = Post::new();

    post.add_text("I ate a salad for lunch today.");
    assert_eq!("", post.content());

    post.request_review();
    assert_eq!("", post.content());

    post.approve();
    assert_eq!("I ate a salad for lunch today.");
}
```

Filename: src/lib.rs
```Rust
pub struct Post {
    state: Option<Box<dyn State>>,
    content: String,
}

impl Post {
    pub fn new() -> Post {
        Post {
            state: Some(Box::new(Draft {})),
            content: String::new(),
        }
    }
    pub fn add_text(&mut self, text: &str) {
        self.content.push_str(text);
    }
    pub fn content(&self) -> &str {
        ""
    }
    pub fn request_review(&mut self) {
        if let Some(s) = self.state.take() { 
            self.state = Some(s.request_review())
        }
    }
    
}

trait State {
	  // takes ownership of self due to it being a Box<Self>
    fn request_review(self: Box<Self>) -> Box<dyn State>;
}

struct Draft {}

impl State for Draft {
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        Box::new(PendingReview {})
    }
}

struct PendingReview {}


impl State for PendingReview {
    fn request_review(self: Box<Self>) -> Box<dyn State> {
        // struct is already waiting to be reviewed in this state
        // so we don't need to change any states
        self
    }
}

```
#### How the Code works
##### Request Review
- is called on a `Post` object
	- `self.state.take()` -> [[2110 Functions on Structs]]
	- `state` isn't being replaced directly(e.g. `self.state = ...)` to ensure we have ownership of the value. This prohibits `Post` from using the old `state` value after change
		- Ownership is needed to avoid a borrowing issue.
			```rust
			self.state = Some(self.state.request_review());
			// first self is borrowing mutably to access the state field.
			// then self is borrowed
			```
- if `state` is `Some`
	- call the state's `request_review()` function
		-> function *consumes* the current `state` and *returns* new `state`
##### Content
```rust
impl Post {
    // --snip--
	pub fn content(&self) -> &str {
		// 1.needs to use `.as_ref(), because we can't get ownership of the state
		//   can't move `state` out of the borrowed `&self` function parameter
		// 2.Unwrap will never `panic!` because we can ensure that it's always a
		//   `Some` value as our functions always return a `Some` value
		// 3.Calling `content()` on the `&Box<dyn State>` -> Deref Coercion
		//   -> will be called on the type implementing the `State` trait
		self.state.as_ref().unwrap().content(self)
	}
    // --snip--
}
```
- see more Information on [[090 Error Handling]]/**Cases in Which you have more Information Then the compiler**
#### Problems
- some duplicate code
- can call `content()` and get a valid `string` even though it's in `draft state`
## Flashcards
