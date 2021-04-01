# 	Linux for Programmers: An Introduction to Linux and SSH

Hello everybody and welcome to a brand new tutorial series on linux 4 programmers now this series is going to aim to make you comfortable using a linux device and teach you the things that you need to know as a programmer about the linux operating system now specifically we're going to be focusing on common linux commands we're also going to be talking about networking ssh we're going to be talking about users and permissions the basic linux text editors that you need to know and then a few more advanced things like cron jobs shell scripts and how you can actually connect a domain with a virtual server now these are all good things to know and as a programmer you do need to have a lot of these skills in fact at many job interviews you will get asked are you comfortable using linux do you know these different linux distributions and depending on your answer to that question you may or may not be getting a job linux is just something that you really should be comfortable with as a programmer and even though you're not going to be using it every single day it's very important that if you do need to work on a linux machine you know how to do so so with that said let's get started in this tutorial series in this first video we're going to be learning how to set up a virtual linux machine and then how to ssh into it

so as i mentioned the first step in this series is to get access to a linux device so you can follow along with the rest of the videos now if you have your own linux device at home that is great but if you don't we have a solution for you and that is lenode now lenode is actually the sponsor of this video and this series and they were kind enough to provide all of you with a free a hundred dollar
credit towards your first lenode servers so if you want to get started using lenode go to the link in the description it should bring you to a page that looks like this and what you need to do is press this create free account button and it will redirect you to a page to create a brand new lenode account where your 100 credit will automatically be applied now lenode is a server hosting company they also have a bunch of other things as well which i'll talk about later but they're awesome i've been using them for over two years i host
websites on lenode i have servers that i use for databases i actually have one of my main domains hosted on lenode so definitely super reliable i trust them and i've been a long time customer and that's why i'm happy to have them sponsoring this video and this series now the last thing that i need to say about lenode is that they're actually going to be providing early access to the later videos in this series so almost all of these videos will be posted on youtube on a regular upload schedule but the last five videos will be on lenode's platform and if you want to get access to them immediately so as soon as i finish filming and editing them then you do need to sign up at this webpage right here they will be posted to youtube at a later date but i don't know that exact date right now so if you want to make sure you have these immediately as soon as they are finished then sign up at this page the link will be in the description and these are the specific videos so shell scripts cron jobs advanced commands deploying a simple python web server and registering a domain on lenode and we're going to be connecting that domain with the web server anyways let's move on now and boot up our first server so at this point in time i'm going to assume that your account is set up and ready to go if it's not pause the video and come back afterwards
anyways now that we're here on the note i'll just quickly walk you through the platform so to create a brand new node you can press this create button here you can also create a bunch of other things like volumes node balancers you can deal with domains on the node in fact i actually host one of my domains on the node as well as two of my servers that i use related to my discord server which you guys should definitely join from the link in the description anyways lenode also has strong integration and support for kubernetes and pretty much anything that you need as a developer you can access here on lenove now let's get started by creating our first server you can see i have two right here but to create one we're going to press the create a node button or create at the top left and then press the node now from here we need to select a few things so the distribution of our lenode the region root password and all of that now for this tutorial series i'm going to be using ubuntu as my distribution so i'm going to pick ubuntu 20.10 i would recommend that you all use ubuntu as well and the rationale behind this is that ubuntu is one of the most common linux distributions a lot of the other linux distributions are fairly similar so a bunch of the stuff that i teach here will actually apply to other linux distributions as well of course there's differences between them but ubuntu is what i'm most comfortable with and familiar with and i figured that's what we should use for this series anyways after we pick our image we can go to our region so i'm going to select toronto ontario and then we can choose our lenode plan so you can see that the cheapest lenod plan and this is really all that we need for this series is five dollars a month and is the nanoed one gigabyte with 25 gigabytes of storage
personally i'm gonna go with the node
four gigabyte just because i want
something that's a little bit faster but
you're welcome to pick whatever you like
and you can also see that they have
dedicated cpu options high memory
options and gpu options as well though
just not in this region
so let's stick with the node 4 gigabyte
and then
let's give a label to our lenove so i'm
just going to call this one tutorial but
i'd highly recommend you call this
something that's meaningful to you
because when you have a lot of the nodes
it's hard to keep track of which one is
which
lastly we need to enter our root
password so i'm going to go ahead and do
that right now
all right so i've entered my password
and we're actually ready to go and
create our first lynn node
now before i do that i will mention that
there's some add-ons like you can add
backups each month and a private ip
address
you also if you wanted a node that's for
a specific purpose so you wanted it
say for like mongodb you're a minecraft
server or something like that
could click on the marketplace and
within the marketplace there's actually
a bunch of options for kind of pre-built
lenods or pre-configured servers
and you can press on this and then
that's actually going to kind of do a
lot of the necessary setup for you for
whatever the application is that you're
running
anyways i just need to go back and
reselect my distribution because we're
not going to choose any of those
marketplace apps but it's really
interesting and definitely makes it much
faster to set something up
so i guess i'm going to have to go back
through and redo a bit of this yes i
need to re-enter my password
but that's fine now we are ready to go
so i'm going to go ahead and press
create and this will just take one
second and then our la node will be
booted up and i will be
right back all right so our lenode is
now running you can see that because we
see
the running icon right here before it
was showing booting and it was kind of a
little yellow icon
now quickly if you want to power off or
reboot your lenode you can press the
buttons right here
we don't really need to mess around with
anything more on this page though
all we need to do is keep track of this
ip address right here so find your
lenods ip address it should just be
under ip addresses you're going to want
the one that's shorter
yours will probably look a little bit
different than this but copy it to your
clipboard and also make sure you
remember your root password because
that's what we're going to need
next so now that we have this ip address
we actually need to ssh into this server
and start doing something on it start
working on the server so now before we
move any further i do need to quickly
thank the other sponsor of this series
which is algo
expert algo expert is the best platform
to use when preparing for your software
engineering coding interviews
i actually work there as an instructor
on the platform and i can highly
recommend it as many high quality coding
interview practice questions
so get started using algo expert today
by hitting the link in the description
and using the code tech with tim for a
discount on the platform
so what i'm going to do now is i'm going
to show you how to ssh into your machine
on mac and then i will show you how to
do so on windows
so on mac it's really straightforward
you don't need to download anything
you simply need to open up your terminal
you can do that by going to the
spotlight search and searching for
terminal
then go inside of your terminal and
simply type ssh
then root at and then the ip address of
your server
after you do that simply press enter it
will likely prompt you with some
question that says yes slash no as the
potential answer
just type yes in there and press enter
and then it should show you a password
field
here at the password field simply type
in the password for your server so what
you set up when you were on
lenode so the root password it's not
going to actually show you any
characters are being typed in but it is
working so just type it in and then
press
enter and then you are good to go you
can now skip through the windows section
but i will show you now how to ssh into
your machine on windows
if you do not have a mac so go to this
website right here i'm going to leave a
link in the description but it's simply
putty.org
and download this tool this is simply an
ssh
client and it just allows us to actually
ssh into our server
it makes it really easy to store all of
the ssh credentials and information and
all of that
so once you've downloaded putty what you
need to do is open that up so you can do
that from the windows bar down here and
you should see an application that looks
something
like this what we're going to do is
we're going to paste our ip address
right into the host name or ip address
field
and then i'm going to show you a few
more things to configure our putty
session
so first of all the port number of 22 is
fine you can leave it like that
you want the connection type to be ssh
and then
close window on exit you're welcome to
select what you want here but i'm going
to leave it only on
clean exit next what i'm going to do is
just make the font size
of my putty window or ssh client or
console or whatever you want to call it
a little bit larger
so i'm going to go to the window thing
here i'm going to go to appearance
i'm going to go here where it says
change and i'm going to change the font
to just be
size 24 just so that you guys can read
this because it's a little bit small
otherwise
you also can change the colors and all
of that from this page but
we don't need to do that anyways let's
go back to session you can see that we
still have the ip address in
and now what we're going to do is just
save the settings that we just put in so
anything that we do or anything that
we're changing
kind of in this putty client it's
usually a good idea just to save it so
we don't have to do this again
so what we're going to do is insert a
name where it says saved sessions
i'm just going to call this tutorial and
then you can go ahead and press
save and that will save all of this
information so just to show you how this
works
if i delete this ip address here and
then i press on tutorial
and i double press it i didn't actually
mean to double press it let me close
this and show you again here
all right so i just had to reopen putty
i don't know i accidentally double
pressed it didn't mean to but if you
press it
and then you press load then you see
that it actually loads the name it loads
the ip
address and if i were to go back to
appearance here you can see the 24
point font is still saved so anyways
this is how you save a session i usually
recommend you to save them and then you
can easily load it after
anyways once you have the ip address in
this field and you've changed all the
settings that you want
go ahead and press open or as you saw
double click on the tutorial thing there
and then this will open up a little
window so when you're prompted with a
little window that looks something like
this just go ahead and press yes there's
no worries with this
and then you should be good and you
should see something that says log
in as now i'm just going to make this
full screen so that it's easier to see
but when it says login as you're going
to log in as the root user it's going to
say
root like that and then it's going to
ask you for the password
now the password is whatever you put in
when you actually set up this land so in
that root password field
so i'm just going to type mine in you're
going to notice that you don't actually
see anything popping up but it is indeed
being typed in
and then once you've typed in the
password press enter
now assuming this password is correct
you should get a screen that looks
something like this
and now you can see information about
your lenode
so at this point in time if you've
successfully logged into your lenode
you have completed this first tutorial
series there's one last thing that we
can do that's usually a good idea which
is just to update the software on our
lenode
but after we do that that's going to
conclude video one and then in video two
we'll move on and talk about some basic
linux commands you need to know so
anyways to end here we're going to
update the software on our lenode by
typing sudo
apt update like that and this will just
run through and update all of the
necessary packages and then the last
thing we're going to do after we update
is we are going to upgrade so we're
going to say sudo
apt hyphen up and then grade
like that then this will upgrade all of
the packages that we need if you're
prompted with something that says
do you want to use this much extra space
just go ahead and type yes
it may prompt you that multiple times
after you type yes
press enter and then you should be good
to go so anyways
now that our server is updated and
upgraded we are ready to continue with this series so i hope you enjoyed 
