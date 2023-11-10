// DOMContentLoaded event ensures that the JavaScript code runs after the HTML content has loaded
document.addEventListener('DOMContentLoaded', function() {
    // Select the elements you want to add interactivity to
    const btn = document.querySelector('.btn-primary');
    const heading = document.querySelector('h1');

    // Add an event listener to the button
    btn.addEventListener('click', function() {
      // Change the text of the heading when the button is clicked
      heading.textContent = 'Button Clicked!';
    });
  });
