import React, { Component } from 'react'
import { Text, View, Button } from 'react-native'

import styles from '../static'
import { getToken } from '../storage'
import LinodeApi from '../client'

function RefreshButton(props) {
  const refresh = () => {
    props.parent.refresh(props.parent)
  }
  return (
    <Button
      style={styles.refresh}
      onPress={refresh}
      color='green'
      title={'Refresh'} />
  )
}

export default class HomeScreen extends Component {
  constructor(props) {
    super(props)
    this.state = {
      events: [],
      token: null
    }
    getToken(this)
    this.api = new LinodeApi()
  }
  componentDidMount() {
    setTimeout(() => { this.refresh(this) }, 50)
  }

  async refresh(that) {
    let events
    that.setState({
      events: {}
    })
    if (that.api.headers.Authorization != `Bearer ${that.state.token}`)
      that.api.setToken(that.state.token)
    if (that.state.token.length == 64) {
      events = await this.api.get('/account/events?page_size=25')
      that.setState({'events': events})
    }
    console.log(that.state.events)
  }

  render() {
    if (typeof this.state.events.data == 'undefined') {
      this.state.events.data = []
    }
    return (
      <View style={styles.container}>
        <Text style={styles.heading}>Events</Text>
        {this.state.events.data.map((event) => {
          return (
            <View>
              <Text style={styles.text}>{event.action}</Text>
            </View>
          )
        })}
        <RefreshButton parent={this} />
      </View>
    )
  }
}
