<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>



<!-- PROJECT LOGO -->
<br />
<div align="center">


<h3 align="center">Amharic Corpus Analysis</h3>

  <p align="center">
     The Amharic Corpus Analysis project is designed to create a comprehensive Amharic language dataset by scraping and aggregating text data from various online sources, filtering out non-Amharic content, and analyzing the word frequency distribution to gain insights into the Amharic language.    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Todos</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][freq-screenshot]](#)
[![Product Name Screen Shot][test-screenshot]](#)
[![Product Name Screen Shot][dist-screenshot]](#)

This project is all about understanding and working with the Amharic language, which is spoken widely in Ethiopia and is one of Africa's most commonly used languages. We're collecting a lot of written Amharic text from different places on the internet, like news articles and websites, to create a valuable resource.

## Key Objectives



1. **Collecting Amharic Text**: We're developing a tool that automatically finds and gathers Amharic text from the internet. This way, we'll have a diverse and up-to-date collection of Amharic language examples.

2. **Separating Amharic Text**: Not all the text we find will be in Amharic. We're building a system that can figure out which parts are in Amharic and remove any text in other languages.

3. **Analyzing Word Frequency**: Once we have our collection of Amharic text, we'll study how often different words are used. This will help us understand which words are most common in the Amharic language.

4. **Checking Zipf's Law**: Many languages, including Amharic, follow a pattern called Zipf's law, where the frequency of words often follows a specific pattern. We'll investigate if Amharic follows this pattern too.

5. **Sharing the Dataset**: Finally, we'll make the curated Amharic collection and our analysis available to the public. This will allow researchers, linguists, and developers to use this valuable dataset for their own work.

Why is this project important?

- **Understanding Amharic**: By studying and analyzing the Amharic language, we can learn more about how it works and how people use it.

- **Creating Useful Tools**: The information we gather can be used to develop helpful language tools, like translation services or AI assistants.

- **Preserving Culture**: Having a collection of Amharic text helps preserve the language and supports educational initiatives to keep Amharic alive and thriving.

- **Empowering the Community**: By sharing the Amharic dataset with everyone, we want to help researchers, developers, and Amharic speakers make the most of this valuable language resource.

If you're interested in learning more about this project or want to contribute, please visit our GitHub repository. We welcome collaborators from different backgrounds, including linguists, developers, and anyone interested in Amharic.

Let's explore and celebrate the richness of the Amharic language together through data-driven analysis and shared resources!

---
Here's a blank template to get started: To avoid retyping too much info. Do a search and replace with your text editor for the following: `github_username`, `repo_name`, `twitter_handle`, `linkedin_username`, `email_client`, `email`, `project_title`, `project_description`

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
* ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)
* ![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites


To build and run this project, you'll need the following installed:

- CMake
- Gnuplot
- Python3

## Build Instructions
1. Clone this repo: 

```
git clone "http://github.com/sss"
```
2. Create a build directory:
   ```
   mkdir build
   cd build
   ```
3. Run CMake to generate the build files:
   ```
   cmake ../
   ```
4. Build the project:
   ```
   cmake --build . --config Release
   ```
5. Run the built executable:
   ```
   ./Release/ACAT
   ```
6. Example Run with Custom Parameters 
```
./Release/ACAT 15 ..\tool\data\frequency_data.txt 1
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


### Using the Tools 

 In order to use tools in /tool directory you can simply install their dependencies by 
```

pip install -r requirements.txt
```

<!-- USAGE EXAMPLES -->
## Usage

1. Make sure you have the necessary dependencies installed.
2. Run the script from the command line:
   ```
   python analyze_word_frequencies.py
   ```
3. Enter the path to the input directory containing the text files.
4. The script will create the `frequency_data_<timestamp>.txt` file in the same directory as the script, containing the sorted word frequencies.



<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## TODO 

- ✅ Visualize word frequency in Amharic language
- ✅ Implement Zipf's distribution
- ◻️ Add more data and analyze the converges the results

## Contribution

🌟 We warmly welcome contributions to this project! Whether you have a bug fix, a feature enhancement, or new ideas, we'd love to see them. Feel free to fork the repository, make your changes, and submit a delightful pull request. Remember, even the tiniest improvements bring us immense joy! Let's make this project shine together. ✨

See the [open issues](https://github.com/github_username/repo_name/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

I warmly welcome contributions to this project! Whether you have a bug fix, a feature enhancement, or new ideas, I would love to see them. Feel free to fork the repository, make your changes, and submit a pull request

Don't forget to give the project a star!
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

  GNU GENERAL PUBLIC LICENSE. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Eual Uchiha - [Telegram](https://t.me/The_Ceaseless_Wheel) - Uchihaeual11@gmail.com
Project Link: [https://github.com/github_username/repo_name](https://github.com/github_username/repo_name)

<p align="right">(<a href="#readme-top">back to top</a>)</p>





<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
[dist-screenshot]: /images/dist.png
[freq-screenshot]: /images/freq.png
[test-screenshot]: /images/test.png
[Python]:(https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)


