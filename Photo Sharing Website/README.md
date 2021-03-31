# Photo-sharing website

Static pre-rendered photo-sharing website to share publicly your pictures without needing to run or maintain servers.

## Concept

- A static website - publicly accessible web app,
- An admin web application - password protected web application (React.js web application) used to generate the static website on demand.


## Architecture

![](assets/photo_sharing_architecture.png)

1. CloudFront distribution with `/` path in S3 bucket as the origin
2. CloudFront distribution with `/website` path in S3 bucket as the origin (the static website static source code)
3. S3 Bucket which holds the all the static resources (html, css, javascript and images)
4. S3 Bucket with the initial uploaded pictures
5. AWS Lambda used to generate the static website's HTML source code
6. AWS Lambda used to generate thumbnails and to detect relevant labels for uploaded photos using Amazon Rekognition
7. Amazon Cognito to provide an authentication for admin user


## Deployment

### Prerequisites
- [Create an AWS account](https://aws.amazon.com/fr/premiumsupport/knowledge-center/create-and-activate-aws-account/)
- [Install the Amplify CLI](https://docs.amplify.aws/cli/start/install#install-the-amplify-cli)
- [Install npm](https://www.npmjs.com/get-npm)

### Instructions

**1. Clone the repository**
  ```
  git clone https://github.com/cornelcroi/photo-sharing-website.git
  ```
**2. Preliminary operations**

- Admin user email
  - replace `your_emailaddress@domain.com` with your own email address in `amplify/backend/boostrap/adminuser/parameters.json`

- Image resize
  - The application resizes images using the `sharp` library packaged as Lambda Layer,
  - The layer is deployed in `eu-west-1` AWS Region so you must deploy the application in this AWS Region. If you plan to deploy to a different Region, follow [this tutorial](https://aws.amazon.com/blogs/compute/using-lambda-layers-to-simplify-your-development-process) to create a sharp layer in that region and then update the layer arn in  `amplify/backend/function/S3TriggeraXXXX/S3TriggeraXXXX-cloudformation-template.json`.

**3. Installs the dependencies**
  ```
  npm install
  ```


**4. Deploy the stack to your AWS account**
  - Initialize your Amplify powered cloud application
    ```
    amplify init
    ```
  - Provisions cloud resources with the local developments run
    ```
    amplify push
    ```
  - Publish static assets to Amazon S3
    ```
    amplify publish
    ```


 ## Tools

- [AWS Amplify JavaScript library](https://docs.amplify.aws/) to connect our front end to cloud resources
- [Amazon Cognito](https://aws.amazon.com/cognito/) to handle admin sign up authorization
- [Amazon Simple Storage Service (S3)](https://aws.amazon.com/s3/) to store and serve as many photos as I wish to upload,, to **host the React.js app** assets for our app and to host the **static generated website**
- [Amazon CloudFront](https://aws.amazon.com/fr/cloudfront/) to store and serve as many photos as our users care to upload, and to host the static assets for our app

- [Amazon DynamoDB](https://aws.amazon.com/dynamodb/) to provide millisecond response times to API queries for album and photo data
- [AWS AppSync](https://aws.amazon.com/appsync/) to host a GraphQL API for our front end
- [AWS Lambda](https://aws.amazon.com/lambda/) to **create photo thumbnails** asynchronously in the cloud & to **generate the static website** on demand
- [Amazon Rekognition](https://aws.amazon.com/rekognition/) to detect 5 labels for each uploaded photo
   

