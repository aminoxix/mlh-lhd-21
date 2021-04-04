import React, { Component } from 'react'
import { Text, View } from 'react-native'

import styles from '../static'

export default class Capabilities extends Component {
  constructor(props) {
    super(props)
  }
  render() {
    if (typeof this.props.parent.state.account.capabilities == 'undefined') {
      return (<View></View>)
    }
    return (
      <View style={styles.sub}>
        {this.props.parent.state.account.capabilities.map((capability,i) => {
          return (
            <View key={i}>
              <Text style={styles.text}>{capability}</Text>
            </View>
          )
        })}
      </View>
    )
  }
}
