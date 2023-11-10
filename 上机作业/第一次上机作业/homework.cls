\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{homework}[A homework style]
\LoadClass[a4paper]{article}
\RequirePackage{ctex}
\RequirePackage{wrapfig}
\RequirePackage{graphicx}
\RequirePackage{psvectorian}
\RequirePackage{microtype}
\RequirePackage{times}
\RequirePackage{multirow}
\RequirePackage{amssymb}
\RequirePackage{amsmath}
\RequirePackage{pdfpages}
\RequirePackage{tikz}
\RequirePackage{pgfplots}
\pgfplotsset{compat=1.17}
\RequirePackage{booktabs}
\RequirePackage{listings}
\RequirePackage{eso-pic}
\RequirePackage{zhnumber}
\RequirePackage{listings}
\usepackage{listings}
\lstset{ %
language=C,                % choose the language of the code
basicstyle=\footnotesize,       % the size of the fonts that are used for the code
numbers=left,                   % where to put the line-numbers
numberstyle=\footnotesize,      % the size of the fonts that are used for the line-numbers
stepnumber=1,                   % the step between two line-numbers. If it is 1 each line will be numbered
numbersep=5pt,                  % how far the line-numbers are from the code
backgroundcolor=\color{white},  % choose the background color. You must add \usepackage{color}
showspaces=false,               % show spaces adding particular underscores
showstringspaces=false,         % underline spaces within strings
showtabs=false,                 % show tabs within strings adding particular underscores
frame=single,           % adds a frame around the code
tabsize=2,          % sets default tabsize to 2 spaces
captionpos=b,           % sets the caption-position to bottom
breaklines=true,        % sets automatic line breaking
breakatwhitespace=false,    % sets if automatic breaks should only happen at whitespace
escapeinside={\%*}{*)}          % if you want to add a comment within your code
}




% disable indent globally
%\setlength{\parindent}{0pt}
% some general improvements, defines the XeTeX logo
\RequirePackage{xltxtra}
% use xifthen
\RequirePackage{xifthen}
% use hyperlink for email and url
\RequirePackage{hyperref}
\hypersetup{hidelinks}
\RequirePackage{url}
\urlstyle{tt}
% use fontawesome
%\RequirePackage{fontawesome}
% use xcolor for customizing color
%\RequirePackage[usenames,dvipsnames]{xcolor}
% loading fonts
\RequirePackage{fontspec}
%Main document font
\setmainfont[
  Path = fonts/Main/ ,
  Extension = .otf ,
  UprightFont = *-regular ,
  BoldFont = *-bold ,
  ItalicFont = *-italic ,
  BoldItalicFont = *-bolditalic ,
  SmallCapsFont = Fontin-SmallCaps
]{texgyretermes}

\RequirePackage[
	a4paper,
	left=0.8in,
	right=0.8in,
	top=0.70in,
	bottom=0.55in,
]{geometry}


\PassOptionsToPackage{dvipsnames,svgnames}{xcolor}
\definecolor{Maroon}{rgb}{0.5,0,0}
\RequirePackage{pgfornament}
\AddToShipoutPicture{%
\begingroup
\setlength{\@tempdima}{2mm}%
\setlength{\@tempdimb}{\paperwidth-\@tempdima-2cm}%
\setlength{\@tempdimc}{\paperheight-\@tempdima}%
\put(\LenToUnit{\@tempdima},\LenToUnit{\@tempdimc}){%
 \pgfornament[anchor=north west,width=2cm,color=Maroon]{63}}

\put(\LenToUnit{\@tempdimb},\LenToUnit{\@tempdimc}){%
  \pgfornament[anchor=north east,width=2cm,symmetry=v,color=Maroon]{63}}
\put(\LenToUnit{\@tempdimb},\LenToUnit{\@tempdima}){%
  \pgfornament[anchor=south east,width=2cm,symmetry=c,color=Maroon]{63}}

  \put(\LenToUnit{\@tempdima},\LenToUnit{\@tempdima}){%
  \pgfornament[anchor=south west,width=2cm,symmetry=h,color=Maroon]{63}}
\endgroup
}




\RequirePackage{titlesec}
\RequirePackage{enumitem}
\setlist{noitemsep} % removes spacing from items but leaves space around the whole list
%\setlist{nosep} % removes all vertical spacing within and around the list
\setlist[itemize]{topsep=0.25em, leftmargin=1.5pc}
\setlist[enumerate]{topsep=0.25em, leftmargin=1.5pc}
\RequirePackage[super]{nth}

\newcommand{\datedsection}[2]{%
  \section[#1]{#1 \hfill #2}%
}
\newcommand{\datedsubsection}[2]{%
  \subsection[#1]{#1 \hfill #2}%
}
\newcommand{\datedline}[2]{%
  {\par #1 \hfill #2 \par}%
}

\newcommand{\name}[1]{
  \leftline{\Huge\scshape{#1}}
  \vspace{1.5ex}
}


\newcounter{timuxuhao}
\setcounter{timuxuhao}{1}
\newcommand{\timu}[1]{\par \vspace{2em}\noindent {\kaishu【题目\zhnum{timuxuhao}】\ #1\stepcounter{timuxuhao}}\par \vspace{0.5em}}

\newcommand{\hwtitle}[3]{
    \begin{center}
        \begin{pspicture}(-5,-1)(5,1)
            \rput[r](-3,-0.2){\psvectorian[color=Maroon,height=1.3cm]{72}}%
            \rput(0,0){\LARGE \textbf{#1}}
     \rput[t](0,-0.7){\psvectorian[color=Maroon,width=8cm]{85}}
     \rput[l](3,-0.2){\psvectorian[color=Maroon,height=1.3cm,mirror]{72}}%
     
        \end{pspicture}
        \thispagestyle{empty}
        \vspace{1em}

        {\large \fangsong #2}
        \vspace{0.5em}

        {\large \fangsong #3}
    
    \end{center}}

\newcommand{\zhengming}{\noindent \textbf{证明：}}
\newcommand{\da}{\noindent \textbf{答：}}
\newcommand{\jie}{\noindent \textbf{解：}}