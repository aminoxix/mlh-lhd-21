import React, { Component } from 'react'
import { Text, View } from 'react-native'

import styles from '../static'

export default class Promotions extends Component {
  constructor(props) {
    super(props)
  }
  render() {
    if (typeof this.props.parent.state.account.active_promotions == 'undefined') {
      return (<View></View>)
    }
    return (
      <View>
        {this.props.parent.state.account.active_promotions.map((promotion,i) => {
          return (
            <View style={styles.sub} key={i}>
              <Text style={styles.text}>{promotion.description}</Text>
              <Text style={styles.text}>Remaing Creadits: {promotion.credit_remaining}$</Text>
            </View>
          )
        })}
      </View>
    )
  }
}
