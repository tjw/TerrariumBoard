## Setup

    % spark list
    Checking with the cloud...
    Retrieving cores... (this might take a few seconds)
    terrarium1 (48ff6a065067555014372387) is online

Copy the identifier into the Makefile

## Install

To compile a build w/o installing

    % make

To compile and install

	% make flash
	    
## Send commands

* Find the access token on the spark.io "Build" settings page and paste it into a file:

    % echo the-token > ~/.spark_access
    % chmod go-rwx ~/.spark_access
    
* Use curl to post a function:

    % curl https://api.spark.io/v1/devices/CORE_ID/FUNCTION -d access_token=TOKEN -d "args=202,230"
  
