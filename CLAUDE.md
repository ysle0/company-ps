# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a company algorithm problem-solving (PS) practice repository. Team members solve coding problems from Programmers (프로그래머스) and commit their solutions.

## Directory Structure

``` plaintext
dates/
  {year}/
    week{NN}/
      {MMDD}-{problem-name}/
        desc.md      # Problem link and metadata
        {username}.{ext}  # Individual solutions
```

- Problems are organized by year and week number
- Each problem folder is named `{date}-{korean-problem-name}`
- `desc.md` contains the Programmers URL, platform name, difficulty level, and problem title
- Solution files are named after the contributor (e.g., `ysl.cpp`, `ysl.cs`)

## Supported Languages

Solutions may be written in:

- C++ (`.cpp`)
- C# (`.cs`)

## Solution Format

Solutions follow the Programmers template format:

- C++: Function `solution()` with appropriate parameters and return type
- C#: Class `Solution` with method `solution()`

No main function or I/O code needed—solutions are designed for the Programmers online judge.

## Running Solutions Locally

**C++:**

```bash
clang++ -o FILENAME FILENAME.cpp
./FILENAME
```

**C#:**

```bash
dotnet run FILENAME.cs
```
