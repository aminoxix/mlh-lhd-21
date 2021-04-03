import './App.css';
import Navbar from 'react-bootstrap/Navbar'
import { Card, Carousel, CarouselItem, Col, Container, Row, Table } from 'react-bootstrap';

function App() {
  return (
    <div className="App">
      <Navbar bg="dark" variant="dark" className="my-nav">
        <Navbar.Brand href="#home">
          React Bootstrap
        </Navbar.Brand>
      </Navbar>

      <Container>

        <Carousel className="gallery">
          <CarouselItem>
            <img src="https://melon.blahajgang.lol/Assets/Graphics/ASMR%20With%20Will/Crunch.png" alt="BLAHAJ" />
          </CarouselItem>
          <CarouselItem>
            <img src="https://melon.blahajgang.lol/Assets/Graphics/Baking%20Streams/BreadHanded.png" alt="BLAHAJ" />
          </CarouselItem>
          <CarouselItem>
            <img src="https://melon.blahajgang.lol/Assets/Graphics/Karaoke%20Night/Avocado.png" alt="BLAHAJ" />
          </CarouselItem>
          <CarouselItem>
            <img src="https://melon.blahajgang.lol/Assets/Graphics/Espresso%20Hour/Cocoa.png" alt="BLAHAJ" />
          </CarouselItem>
        </Carousel>

        <Row>
          <Col xs={12} md={8}>
            <p>At LHD: Share, we will have plenty of week-long and daily challenges to keep you busy. Week-long challenges will be accessible for the entire week, so you can hack on them whenever you have free time. Daily challenges are only available for 24 hours after they’re originally posted, so make sure you come back each day to see which challenges you’re going to conquer.</p>
            <p>Challenges will range from social challenges urging you to connect with other members of the community, technical challenges that will expand your coding skills, and design challenges to refine your skills as a creator and artist. Some of these challenges will be completed live on our twitch stream, so you can follow along and complete it with the community. We cannot wait to see all that you learn, build, and share.</p>
            
            <Table striped bordered hover>
              <thead>
                <tr>
                  <th>#</th>
                  <th>Guild Name</th>
                  <th>Points</th>
                  <th>Members</th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <td>1</td>
                  <td>BLAHAJgang</td>
                  <td>10,841</td>
                  <td>318</td>
                </tr>
                <tr>
                  <td>2</td>
                  <td>EddieHub</td>
                  <td>6,212</td>
                  <td>278</td>
                </tr>
                <tr>
                  <td>3</td>
                  <td>Developer Student Community</td>
                  <td>4,948</td>
                  <td>248</td>
                </tr>
              </tbody>
            </Table>

          </Col>
          <Col xs={12} md={4}>
            <Card className="ikea-ad">
              <Card.Body>
                <Card.Title>Buy a BLAHAJ</Card.Title>
                <Card.Subtitle className="mb-2">They are the best</Card.Subtitle>
                <img src="https://blahajgang.lol/assets/just-blahaj.png" alt="BLAHAJ"/>
                <Card.Text>
                  Ryan sWift is a huge fan of BLAHAJ and he really wants you to buy one. If you don't, he'll be sad. Also 45k Checkins pls.
                </Card.Text>
                <Card.Link href="https://hackp.ac/blahaj">Buy one today</Card.Link>
              </Card.Body>
            </Card>
            <Card style={{ width: '18rem' }}>
              <Card.Body>
                <Card.Title>Attend Local Hack Day</Card.Title>
                <Card.Subtitle className="mb-2 text-muted">They are the best</Card.Subtitle>
                <Card.Text>
                  Earn points pls.
                </Card.Text>
                <Card.Link href="https://lhd.mlh.io">Register</Card.Link>
              </Card.Body>
            </Card>
          </Col>
        </Row>
      </Container>
      
    </div>
  );
}

export default App;
